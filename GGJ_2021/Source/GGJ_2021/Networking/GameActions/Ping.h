#pragma once

#include "CoreMinimal.h"
#include "GameAction.h"
#include "Ping.generated.h"

/**
 * Ping asks the server to reply with a pong and does nothing else
 */
USTRUCT()
struct FGameActionPing : public IGameAction {
  GENERATED_BODY()

public:
  FGameActionPing();
  //virtual ~FGameActionPing();

  virtual int32 serialize(uint8 *buffer, int32 buf_size) override;

private:
  UPROPERTY()
  FString type;
};