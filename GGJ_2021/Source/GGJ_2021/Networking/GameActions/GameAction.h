#pragma once

#include "CoreMinimal.h"
#include "Dom/JsonObject.h"

/**
 * GameActions are possible events clients can invoke on the server.
 */
class GGJ_2021_API GameAction {
public:
  uint* compile() virtual;

private:
  int _id;
};