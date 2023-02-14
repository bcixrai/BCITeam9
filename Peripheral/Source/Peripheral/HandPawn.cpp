// Fill out your copyright notice in the Description page of Project Settings.


#include "HandPawn.h"

#include "Components/SceneComponent.h"
#include "MotionControllerComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AHandPawn::AHandPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene component"));
	SetRootComponent(Scene);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	Right = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Right motion controller"));
	Right->SetupAttachment(RootComponent);

	Left = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Left motion controller"));
	Left->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHandPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AHandPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHandPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

