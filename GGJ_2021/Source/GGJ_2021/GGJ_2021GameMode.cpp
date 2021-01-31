// Copyright Epic Games, Inc. All Rights Reserved.

#include "GGJ_2021GameMode.h"
#include "GGJ_2021Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Networking/NetworkClient.h"

AGGJ_2021GameMode::AGGJ_2021GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// Do a real quick test of the server connection, real quicky likey
	UNetworkClient client;

	if(client.connect(FIPv4Address(10, 1, 1, 1), 8732)) {
    UE_LOG(LogTemp, Display, TEXT("Connected?"));

    //uint8 data[] = "{ \"type\": \"ping\" }";
    //int32 bytes_sent;

    //client.Send(data, sizeof(data), bytes_sent);
    //Socket->Recv(data, sizeof(data), bytes_sent);

    //FString msg = BytesToString(data, sizeof(data));

    //UE_LOG(LogTemp, Fatal, TEXT("GOT A RESPONSE!!!!!111 -> %s"), *msg);

    client.disconnect();
  } else {
    UE_LOG(LogTemp, Display, TEXT("NOT CONNECTED!"));
  }
}
