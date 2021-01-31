// Copyright Epic Games, Inc. All Rights Reserved.

#include "GGJ_2021GameMode.h"
#include "GGJ_2021Character.h"
#include "UObject/ConstructorHelpers.h"
#include "HexPlayerController.h"

AGGJ_2021GameMode::AGGJ_2021GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AHexPlayerController::StaticClass();
}
