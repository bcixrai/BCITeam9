// Fill out your copyright notice in the Description page of Project Settings.


#include "VRPlayerController.h"
#include "VRPlayer.h"
//void AVRPlayerController::OnPossess(APawn* pawn)
//{
//	Super::OnPossess(pawn);
//
//	mPlayer = Cast<AVRPlayer>(pawn);
//	if (!mPlayer) {
//
//		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("PC : Not a AVRPlayer"));
//		return;
//	}
//	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("VRPlayer Possesed"));
//}

void AVRPlayerController::BeginPlay()
{
	
	Super::BeginPlay();

	mVRPlayer = Cast<AVRPlayer>(GetPawn());
	if (!mVRPlayer) {
	}
}

void AVRPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
