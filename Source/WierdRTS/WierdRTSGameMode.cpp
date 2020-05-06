// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "WierdRTSGameMode.h"
#include "WierdRTSPlayerController.h"
#include "WierdRTSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWierdRTSGameMode::AWierdRTSGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AWierdRTSPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}