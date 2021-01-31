use clap::Clap;
use std::net::SocketAddr;

#[derive(Clap, Debug, Clone)]
#[clap(name = "Server for GGJ2021", about = "Holds the gamestate and handles actions from and updates to clients.")]
pub struct Settings {
  #[clap(short, long)]
  pub debug : bool,

  #[clap(short, long, default_value = "0.0.0.0:8732")]
  pub address : SocketAddr
}