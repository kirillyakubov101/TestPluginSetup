// Fill out your copyright notice in the Description page of Project Settings.


#include "PluginActivatorBase.h"
#include "GameFeaturesSubsystem.h"

// Sets default values for this component's properties
UPluginActivatorBase::UPluginActivatorBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPluginActivatorBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPluginActivatorBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPluginActivatorBase::ActivatePlugin(const FString& PluginName)
{
	FString PluginURL;

	// Get the Plugin URL based on the Game Features Name
	UGameFeaturesSubsystem::Get().GetPluginURLForBuiltInPluginByName(PluginName, PluginURL);

	UGameFeaturesSubsystem::Get().LoadAndActivateGameFeaturePlugin(PluginURL, FGameFeaturePluginLoadComplete());

	ListOfGameFeatures.Add(PluginURL);

}

void UPluginActivatorBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	for(const auto & ele : ListOfGameFeatures)
	{
		UGameFeaturesSubsystem::Get().DeactivateGameFeaturePlugin(ele);
	}
}



//// Deactivate the Game Feature
	//UGameFeaturesSubsystem::Get().DeactivateGameFeaturePlugin(PluginURL);

	//// Activate the Game Feature
	//UGameFeaturesSubsystem::Get().LoadAndActivateGameFeaturePlugin(PluginURL, FGameFeaturePluginLoadComplete());

	//// Unload the Game Feature
	//UGameFeaturesSubsystem::Get().UnloadGameFeaturePlugin(PluginURL);

	//// Load the Game Feature
	//UGameFeaturesSubsystem::Get().LoadGameFeaturePlugin(PluginURL, FGameFeaturePluginLoadComplete());