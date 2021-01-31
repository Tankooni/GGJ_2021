use crate::error::*;
use crate::Settings;
use crate::gamestate::GameState;
use super::ClientConnection;
use crate::game_actions::GameActions;
use crate::client_updates::ClientUpdate;

use log::*;
use tokio::{
  net::TcpListener,
  //sync::watch::{self, Receiver},
  select,
  try_join,
  time::{self, Duration},
};
use async_channel::{unbounded, Sender, Receiver};

pub struct GameServer {
  gamesettings : Settings
}

impl GameServer {
  pub fn new(settings : Settings) -> Self {
    GameServer{
      gamesettings: settings
    }
  }

  pub async fn run(&mut self) -> Result<()> {
    let (update_tx, update_rx) = unbounded();
    let (action_tx, action_rx) = unbounded();
    let settings = self.gamesettings.clone();
    let mut gamestate = GameState::new();

    // create the listener
    let client_listener = tokio::spawn(async move {
      if let Err(e) = Self::listen(settings, update_rx, action_tx).await {
        error!("Fatal Server Error: {}", e);
      }
    });
    

    // tick rate is hardcoded to 60/sec
    let interval = tokio::spawn(async move {
      let mut inter = time::interval(Duration::from_millis(100));
      loop {
        inter.tick().await;

        if let Err(e) = Self::tick(&mut gamestate, update_tx.clone(), action_rx.clone()).await {
          error!("Error while processing tick: {}", e);
        }
      }
    });

    try_join!(client_listener, interval)?;

    Ok(())
  }

  async fn listen(settings : Settings, update_rx : Receiver<ClientUpdate>, action_tx : Sender<GameActions>) -> Result<()> {
    // Start listening for clients
    let listener = TcpListener::bind(settings.address).await?;

    info!("Listening for clients on {}.", settings.address);
    loop {
      let update_rx = update_rx.clone();
      let action_tx = action_tx.clone();
      let (stream, addr) = listener.accept().await?;

      // We got a connection! Commence hand vibrations
      // (let's just assume we got a working thing for now)
      tokio::spawn(async move {
        info!("Got a connection from {}.", addr);
        let mut client = ClientConnection::new(addr, stream);
        loop {
          select! {
            action = client.read_action() => match action {
              Ok(action) => {
                // enqueue the action
                action_tx.send(action).await.unwrap();
              }
              Err(e) => {
                // just drop the connection and log an error
                error!("Dropping connection to {}. Reason: {}", addr, e);
                break;
              }
            },
            update = update_rx.recv() => {
              if let Ok(update) = update {
                if let Err(e) = client.send_update(update.clone()).await {
                  warn!("Failed to send data to {}. Dropping: {}", addr, e);
                  break;
                }
              }
            }
          }
        }
      });
    }
  }

  async fn tick(
    _gamestate : &mut GameState,
    update_tx : Sender<ClientUpdate>,
    action_rx : Receiver<GameActions>
  ) -> Result<()> 
  {
    // process queued actions
    while let Ok(action) = action_rx.try_recv() {
      debug!("Got an action: {:?}", action);
      match action {
        GameActions::Ping(_) => update_tx.send(ClientUpdate::Pong).await?,
      }
    }

    Ok(())
  }
}