// Fill out your copyright notice in the Description page of Project Settings.


#include "PeripheralHandActor.h"

// Sets default values
APeripheralHandActor::APeripheralHandActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APeripheralHandActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APeripheralHandActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APeripheralHandActor::AttachToMotionController(UMotionControllerComponent* mc)
{

	return false;
}

bool APeripheralHandActor::AttachToMotionController()
{
	return false;
}

bool APeripheralHandActor::DetachFromMotionController(UMotionControllerComponent* mc)
{
	return false;
}

bool APeripheralHandActor::DetachFromMotionController()
{
	return false;
}

void APeripheralHandActor::SetMotionController(UMotionControllerComponent* mc)
{
}

