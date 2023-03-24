// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Interactable.h"
#include "Peripheral.h"
#include "AnimalInteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PERIPHERAL_API UAnimalInteractionComponent : public USceneComponent, public Interactable
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAnimalInteractionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	class AAnimal* mAnimal;

	virtual FInteractionResult Interact(AActor* interactor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EAnimalInteractionType> mReactionType = HAPPY;
};
