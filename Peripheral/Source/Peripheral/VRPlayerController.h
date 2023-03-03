// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VRPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PERIPHERAL_API AVRPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	//virtual void OnPossess(APawn* pawn) override;

	class AVRPlayer* mPlayer;
};
