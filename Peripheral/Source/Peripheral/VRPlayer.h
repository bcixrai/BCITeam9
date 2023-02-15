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
	//This VRPlayer should be able to be used for both VR and non-VR
	AVRPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	//Hands
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMotionControllerComponent* mRightMC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMotionControllerComponent* mLeftMC;

	//Simple VR mode mechanic
	bool IsVR() {
		return bVR;
	};
	bool StartVR();
	bool StopVR();

	//Simple BCI mode mechanic
	bool UsingBCI() {
		return bUseBCI;
	}
	void SetUseBCI(bool bci) {
		bUseBCI = bci;
	}

	//Grabbing stuff
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float mGrabRadius = 200.f;
	UFUNCTION(BlueprintImplementableEvent, Category = "Input")
		void GripRightHand_Pressed();
	UFUNCTION(BlueprintImplementableEvent, Category = "Input")
		void GripRightHand_Released();
	UFUNCTION(BlueprintImplementableEvent, Category = "Input")
		void GripLeftHand_Pressed();
	UFUNCTION(BlueprintImplementableEvent, Category = "Input")
		void GripLeftHand_Released();

	class UGrabComponent* GetNearestGrabComponent(UMotionControllerComponent* mc);
	std::vector<UGrabComponent*> GetNearbyGrabComponents(UMotionControllerComponent* mc);
	
	std::unordered_map<UMotionControllerComponent*, UGrabComponent*> mGrabs;
	UGrabComponent* GetGrabbed(UMotionControllerComponent* mc);
	//Is the mc parameter currently holding an item
	bool GrabbingItem(UMotionControllerComponent* mc);
private:
	bool bUseBCI = false;


	bool bVR = false;

};
