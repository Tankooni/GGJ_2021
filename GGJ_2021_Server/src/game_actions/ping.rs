use super::game_action::*;

use serde::{Serialize, Deserialize};

#[derive(Serialize, Deserialize, Debug, Clone)]
pub struct ActionPing {}

impl GameAction for ActionPing {}