// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestPluginSetupGameMode.h"
#include "TestPluginSetupCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestPluginSetupGameMode::ATestPluginSetupGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
