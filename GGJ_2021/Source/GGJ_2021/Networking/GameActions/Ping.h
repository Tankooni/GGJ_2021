#pragma once

#include "CoreMinimal.h"
#include "Ping.generated.h"

/**
 * Ping asks the server to reply with a pong and does nothing else
 */
USTRUCT()
struct FGameActionPing {
  GENERATED_BODY()

  FGameActionPing();
  ~FGameActionPing();

  int32 serialize(uint8 *buffer, int32 buf_size);

private:
  UPROPERTY()
  FString type;
};