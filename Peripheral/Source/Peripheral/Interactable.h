// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */


struct FInteractionResult {
		//Maybe some sort of PeripheralAgent
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* mFirstInteractor = nullptr;
	//Maybe some sort of PeripheralAgent
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* mSecondInteractor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString mMessage = "Interaction Finished";
};
class PERIPHERAL_API Interactable
{
public:
	Interactable();
	~Interactable();

	virtual FInteractionResult Interact(AActor* interactor) = 0;
};

