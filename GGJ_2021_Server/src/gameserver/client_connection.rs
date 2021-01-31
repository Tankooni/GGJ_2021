use crate::error::*;
use crate::game_actions::GameActions;
use crate::client_updates::ClientUpdate;

use log::*;
use std::{
  net::SocketAddr,
};
use tokio::{
  net::TcpStream,
  io::{AsyncReadExt, AsyncWriteExt},
};
use bytes::{Buf, BytesMut};

pub struct ClientConnection {
  addr: SocketAddr,
  socket : TcpStream,
  buffer : BytesMut
}

impl ClientConnection {
  pub fn new(addr : SocketAddr, socket : TcpStream) -> Self {
    ClientConnection {
      addr,
      socket,
      buffer: BytesMut::with_capacity(4096)
    }
  }

  pub async fn send_update(&mut self, update : ClientUpdate) -> Result<()> {
    let data = serde_json::to_vec(&update).unwrap();
    self.socket.write_all(data.as_slice()).await?;
    Ok(())
  }

  pub async fn read_action(&mut self) -> Result<GameActions> {
    // Do it the dumb way for now because this streaming rabbithole
    // is way to deep
    loop {
      if let Some(frame) = self.parse_frame() {
        return Ok(frame);
      }

      if 0 == self.socket.read_buf(&mut self.buffer).await? {
        return Err(Error::NetError(format!("Connection terminated for peer {}", self.addr)));
      }
    }
  }

  fn parse_frame(&mut self) -> Option<GameActions> {
    if self.buffer.len() == 0 {
      return None;
    }

    // count how many curly braces we have. If > 1 and they match, we're good

    // delete all non-{ because it isn't valid
    if self.buffer[0] != b'{' {
      warn!("Invalid data detected in buffer for {}! Clearing...", self.addr);

      let mut i : usize = 0;
      while i < self.buffer.len() && self.buffer[i] != b'{' { i+= 1 }
      warn!("Cleared {} bytes: {:?}", i, String::from_utf8_lossy(&self.buffer[..i]));

      if i >= self.buffer.len() {
        warn!("Buffer is entirely garbage data. Clearing...");
        self.buffer.clear();
        return None;
      } else {
        self.buffer.advance(i);
      }
    }

    // Check if we have an entire json object
    let mut curls = 0;
    let mut res = None;
    for (i, c) in self.buffer.iter().enumerate() {
      match c {
        b'{' => curls += 1,
        b'}' => curls -= 1,
        _ => continue
      }

      if curls <= 0 {
        match serde_json::from_slice(&self.buffer[..i+1]) {
          Ok(action) => res = action,
          Err(_) => warn!("Received invalid action: {}", String::from_utf8_lossy(&self.buffer[..i+1])),
        }

        self.buffer.advance(i+1);
        break;
      }
    }

    res
  }
}