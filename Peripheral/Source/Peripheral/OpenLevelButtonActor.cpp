// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenLevelButtonActor.h"
#include "PeripheralGameInstance.h"
// Sets default values
AOpenLevelButtonActor::AOpenLevelButtonActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOpenLevelButtonActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOpenLevelButtonActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FInteractionResult AOpenLevelButtonActor::Interact(AActor* interactor)
{
	FInteractionResult result;

	result.mFirstInteractor = interactor;
	result.mSecondInteractor = this;

	result.mMessage = "Open Level" + mLevelName.ToString();

	return result;
}


