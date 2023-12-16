// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project_NGameMode.h"
#include "Project_NPlayerController.h"
#include "Project_NCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject_NGameMode::AProject_NGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AProject_NPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}