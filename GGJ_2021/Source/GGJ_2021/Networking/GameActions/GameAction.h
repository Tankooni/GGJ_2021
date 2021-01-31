#pragma once

#include "CoreMinimal.h"
#include "GameAction.generated.h"

UINTERFACE(MinimalAPI)
class UGameAction : public UInterface {
  GENERATED_BODY()
};

class IGameAction {
  GENERATED_BODY()
public:
  virtual int32 serialize(uint8 *buffer, int32 buf_size);
};