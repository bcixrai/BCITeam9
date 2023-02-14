// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRPlayer.generated.h"

UCLASS()
class PERIPHERAL_API AVRPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Grabbing stuff
	UFUNCTION(BlueprintNativeEvent, Category = "Input")
		void GripLeftHand_Pressed();
	UFUNCTION(BlueprintNativeEvent, Category = "Input")
		void GripRightHand_Pressed();
	UFUNCTION(BlueprintNativeEvent, Category = "Input")
		void GripLeftHand_Released();
	UFUNCTION(BlueprintNativeEvent, Category = "Input")
		void GripRightHand_Released();
};
