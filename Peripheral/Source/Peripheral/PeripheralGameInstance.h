// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PeripheralGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PERIPHERAL_API UPeripheralGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void SetSelectedMapNameString(FString name) {
		mSelectedMapNameString = name;
	};
	UFUNCTION(BlueprintCallable)
		FString GetSelectedMapNameString() {
		return mSelectedMapNameString;
	};
private:
	FString mSelectedMapNameString = "";
};
