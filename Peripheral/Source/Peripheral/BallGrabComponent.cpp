// Fill out your copyright notice in the Description page of Project Settings.


#include "BallGrabComponent.h"

void UBallGrabComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if (bCheckForThrow) {
		mCurrentTime += DeltaTime;

		if (mCurrentTime > mCheckForThrowTime) {
			//Find out how fast it moved this 0.1 seconds
			auto dist = FVector::Distance(mReleasedLocation, GetOwner()->GetActorLocation());

			float speed = (dist / 100.f)/ mCurrentTime;

			GEngine->AddOnScreenDebugMessage(113, 10, FColor::Cyan, FString::Printf(TEXT("Ball : %f meters per second"), mCheckForThrowTime, speed));
			if (speed > mRequiredMetersPerSecond) {
				GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, FString::Printf(TEXT("Ball : Registered throw at %f meters per second over %f seconds"), speed, mCheckForThrowTime));

			}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("Ball : No throw at %f meters per second over %f seconds"), speed, mCheckForThrowTime));

			}

			//Finished checking
			bCheckForThrow = false;
		}
		
	}
}

void UBallGrabComponent::OnGrabbed()
{
}

void UBallGrabComponent::OnReleased()
{
	//Start timer
	bCheckForThrow = true;
	mCurrentTime = 0;
	mReleasedLocation = GetOwner()->GetActorLocation();
}
