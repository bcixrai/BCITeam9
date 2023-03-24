// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalAnimationInstance.h"
#include "Animal.h"
void UAnimalAnimationInstance::NativeInitializeAnimation()
{
	mAnimal = Cast<AAnimal>(TryGetPawnOwner());
	if (!mAnimal) {
		//Something very wrong
	}
}

void UAnimalAnimationInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (!mAnimal) {
		return;
	}
	mSpeed = mAnimal->GetCurrentSpeed();

	bTaunting = mAnimal->GetMode() == TAUNT ? true : false;
}
