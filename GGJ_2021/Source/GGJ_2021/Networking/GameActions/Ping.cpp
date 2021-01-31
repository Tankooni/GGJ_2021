#include "Ping.h"

GameActionPing::GameActionPing() {
  this->_id = 1;
}

GameActionPing::~GameActionPing() {
  
}

uint8* GameActionPing::compile() {
  FJsonObject obj;
  obj.SetNumberField("_id", this->_id);

  return obj.
}