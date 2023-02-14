// Fill out your copyright notice in the Description page of Project Settings.


#include "VRPlayer.h"

// Sets default values
AVRPlayer::AVRPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVRPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("GrabRight", IE_Pressed, this, &AVRPlayer::GripRightHand_Pressed);
	InputComponent->BindAction("GrabRight", IE_Released, this, &AVRPlayer::GripRightHand_Released);

	InputComponent->BindAction("GrabLeft", IE_Pressed, this,   &AVRPlayer::GripLeftHand_Pressed);
	InputComponent->BindAction("GrabLeft", IE_Released, this,  &AVRPlayer::GripLeftHand_Released);
}

void AVRPlayer::GripRightHand_Pressed_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Right Hand Grip Pressed"));
	UE_LOG(LogTemp, Log, TEXT("Right Hand Grip Released"));
}
void AVRPlayer::GripRightHand_Released_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Right Hand Grip Released"));
	UE_LOG(LogTemp, Log, TEXT("Rigth Hand Grip Released"));
}

void AVRPlayer::GripLeftHand_Pressed_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Left Hand Grip Pressed"));
	UE_LOG(LogTemp, Log, TEXT("Left Hand Grip Pressed"));
}
void AVRPlayer::GripLeftHand_Released_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Left Hand Grip Released"));
	UE_LOG(LogTemp, Log, TEXT("Left Hand Grip Released"));
}
