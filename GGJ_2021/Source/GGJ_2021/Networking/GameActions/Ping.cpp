#include "Ping.h"
#include "Json.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"
#include "Runtime/Core/Public/Containers/UnrealString.h"


FGameActionPing::FGameActionPing()
  : type("ping") {}

FGameActionPing::~FGameActionPing() {}

int32 FGameActionPing::serialize(uint8 *buffer, int32 buf_size) {
  FString json;

  if(!FJsonObjectConverter::UStructToJsonObjectString(*this, json, 0, 0)) {
    UE_LOG(LogTemp, Warning, TEXT("AHHHHHHHHHHHHHHH"));
  }

  return StringToBytes(json, buffer, buf_size);
}