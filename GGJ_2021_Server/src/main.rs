use clap::Clap;
use log::{info, error, debug};

mod error;
mod settings;
mod game_actions;
mod client_updates;
mod gamestate;
mod gameserver;

use settings::Settings;


#[tokio::main]
async fn main() {
  // load settings
  let settings = Settings::parse();

  // set up logging
  let log_level = if settings.debug { "debug" } else { "info" };
  env_logger::Builder::from_env(env_logger::Env::default().default_filter_or(log_level)).init();

  // Print environment info
  debug!("Settings: {:?}", settings);

  // Create our server and listen for connections until shutdown
  let mut server = gameserver::GameServer::new(settings);
  if let Err(e) = server.run().await {
    error!("Error: {}", e);
  } else {
    info!("Server shutdown successfully");
  }
}
