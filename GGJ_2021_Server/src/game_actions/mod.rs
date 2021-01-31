pub mod ping;
pub mod game_action;

use serde::{Serialize, Deserialize};

#[derive(Serialize, Deserialize, Clone, Debug)]
#[serde(tag = "type")]
pub enum GameActions {
  #[serde(rename = "ping")]
  Ping(ping::ActionPing)
}