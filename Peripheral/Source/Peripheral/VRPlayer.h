// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRPlayer.generated.h"

UENUM()
enum EHandSide{ right, left};

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

	class UPeripheralGameInstance* mPeripheralGI;
	//Hands
	class APeripheralHandActor* mRightHand;
	APeripheralHandActor* mLeftHand;

	TMap<EHandSide, APeripheralHandActor*> mHandsMap;
	std::vector< APeripheralHandActor*> mHandsVector;
	TArray<APeripheralHandActor*> mHandsArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMotionControllerComponent* mRightMC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMotionControllerComponent* mLeftMC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UChildActorComponent* mRightHandChildActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UChildActorComponent* mLeftHandChildActor;
	void AlignHandAndMotionController(APeripheralHandActor* hand, UMotionControllerComponent* mc);
	void AlignHandAndMotionController(EHandSide side);
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
	void GripRightHand_Pressed();
	void GripRightHand_Released();
	void GripLeftHand_Pressed();
	void GripLeftHand_Released();

	class UGrabComponent* GetNearestGrabComponent(UMotionControllerComponent* mc);
	std::vector<UGrabComponent*> GetNearbyGrabComponents(UMotionControllerComponent* mc);
	
	std::unordered_map<UMotionControllerComponent*, UGrabComponent*> mGrabs;
	UGrabComponent* GetGrabbed(UMotionControllerComponent* mc);
	//Is the mc parameter currently holding an item
	bool GrabbingItem(UMotionControllerComponent* mc);

	//Teleporting
	void Teleport_Pressed();
	void Teleport_Released();
	bool TryTeleport();
	bool IsValidTeleportLocation(FHitResult hit);

	FHitResult GetTeleportAimHit();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* mTeleportGraphic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* mTeleportAimStart;
	class UStaticMeshComponent* mTeleportAimMesh;
	UPROPERTY(EditAnywhere)
		class UMaterial* mCanTeleportMat;
	UPROPERTY(EditAnywhere)
		class UMaterial* mCantTeleportMat;
private:
	bool bUseBCI = false;


	bool bVR = false;

	bool bTeleporting = false;
	float mTeleportMaxRange = 1000.f;


	FVector mTeleportLocation;
};
