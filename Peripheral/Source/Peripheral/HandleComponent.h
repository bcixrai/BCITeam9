// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GrabComponent.h"
#include "HandleComponent.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum EHandleRotationAxis{ X, Y, Z};
UCLASS()
class PERIPHERAL_API UHandleComponent : public UGrabComponent
{
	GENERATED_BODY()
public:
		// Called every frame
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		virtual bool TryGrab(class UMotionControllerComponent* mc) override;

		virtual bool TryRelease() override;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			EHandleRotationAxis mRotationAxis = X;

		float mLastRotValue = 0;
};
