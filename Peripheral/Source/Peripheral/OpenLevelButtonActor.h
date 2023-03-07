// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "OpenLevelButtonActor.generated.h"

UCLASS()
class PERIPHERAL_API AOpenLevelButtonActor : public AActor, public Interactable
{
	
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOpenLevelButtonActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual FInteractionResult Interact(AActor* interactor);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName mLevelName;
};
