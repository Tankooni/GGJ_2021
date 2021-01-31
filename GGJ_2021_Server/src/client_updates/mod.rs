mod pong;

pub use pong::*;

use serde::{Serialize, Deserialize};

#[derive(Serialize, Deserialize, Clone, Debug)]
#[serde(tag = "type")]
pub enum ClientUpdate {
  #[serde(rename = "pong")]
  Pong
}
