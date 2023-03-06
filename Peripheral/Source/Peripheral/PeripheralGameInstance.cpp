// Fill out your copyright notice in the Description page of Project Settings.


#include "PeripheralGameInstance.h"
#include "Kismet/GameplayStatics.h"
UPeripheralGameInstance::UPeripheralGameInstance()
{
	
}
bool UPeripheralGameInstance::RequestOpenLevelByName(FName name)
{
	bool bContinueDespite = true;
	if (!mLevels.Contains(name)) {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("This level is not found")));
		if (!bContinueDespite) {
			return false;
		}
	}

	UGameplayStatics::OpenLevel(this, name);
	
	return true;
}
