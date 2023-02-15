// Fill out your copyright notice in the Description page of Project Settings.


#include "VRPlayer.h"

#include "MotionControllerComponent.h"
#include "GrabComponent.h"
#include "Kismet/KismetSystemLibrary.h"
// Sets default values
AVRPlayer::AVRPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Right hand
	mRightMC = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MC Right"));
	mRightMC->bEditableWhenInherited = true;
	mRightMC->MotionSource = "Right";

	//Left hand
	mLeftMC = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MC Left"));
	mLeftMC->bEditableWhenInherited = true;
	mLeftMC->MotionSource = "Left";

}

// Called when the game starts or when spawned
void AVRPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	//What do we want to do different here
}

// Called every frame
void AVRPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("GrabRight", IE_Pressed, this, &AVRPlayer::GripRightHand_Pressed);
	InputComponent->BindAction("GrabRight", IE_Released, this, &AVRPlayer::GripLeftHand_Released);

	InputComponent->BindAction("GrabLeft", IE_Pressed, this,   &AVRPlayer::GripLeftHand_Pressed);
	InputComponent->BindAction("GrabLeft", IE_Released, this,  &AVRPlayer::GripLeftHand_Released);
}


#pragma region VR
bool AVRPlayer::StartVR()
{
	bVR = true;
	return true;
}

bool AVRPlayer::StopVR()
{
	bVR = false;
	return true;

}

#pragma endregion

#pragma region Grab
void AVRPlayer::GripRightHand_Pressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Right Hand Grip Pressed"));
	UE_LOG(LogTemp, Log, TEXT("Right Hand Grip Pressed"));
	auto grab = GetNearestGrabComponent(mRightMC);
	if (!grab) {
		return;
	}
	bool grabbed = grab->TryGrab(mRightMC);
	if (!grabbed) {
		return;
	}
	mGrabs[mRightMC] = grab;
}
void AVRPlayer::GripRightHand_Released()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Right Hand Grip Released"));
	UE_LOG(LogTemp, Log, TEXT("Rigth Hand Grip Released"));
	auto grab = GetNearestGrabComponent(mRightMC);
	if (!grab) {
		return;
	}
	bool released = grab->TryRelease();
	if (!released) {
		return;
	}
	mGrabs[mRightMC] = nullptr;
}
void AVRPlayer::GripLeftHand_Pressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Left Hand Grip Pressed"));
	UE_LOG(LogTemp, Log, TEXT("Left Hand Grip Pressed"));
	auto grab = GetNearestGrabComponent(mLeftMC);
	if (!grab) {
		return;
	}
	bool grabbed = grab->TryGrab(mLeftMC);
	if (!grabbed) {
		return;
	}
	//Grabbed it
	mGrabs[mLeftMC] = grab;

}
void AVRPlayer::GripLeftHand_Released()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Left Hand Grip Released"));
	UE_LOG(LogTemp, Log, TEXT("Left Hand Grip Released"));
	if (!mGrabs[mLeftMC]) {
		return;
	}

	bool released = mGrabs[mLeftMC]->TryRelease();
	if (!released) {
		return;
	}
	mGrabs[mLeftMC] = nullptr;
}

UGrabComponent* AVRPlayer::GetNearestGrabComponent(UMotionControllerComponent* mc)
{
	//Find all close by grabcomponents
	auto grabs = GetNearbyGrabComponents(mc);

	//Iterate trough distance
	UGrabComponent* nearest = nullptr;
	float distance = 1000.f;
	for (auto& grab : grabs) {
		//Get distance from
		float dist = FVector::Distance(grab->GetComponentLocation(), mc->GetComponentLocation());
		if (dist < distance) {
			nearest = grab;
			distance = dist;
		}
	}
	return nearest;
}

std::vector<UGrabComponent*> AVRPlayer::GetNearbyGrabComponents(UMotionControllerComponent* mc)
{
	//Object types
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesArray;
	ObjectTypesArray.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel1));

	//What actors to ignore
	TArray<AActor*> ignored;
	ignored.Add(this);

	TArray<FHitResult> hits;
	bool bHasHit = UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), mc->GetComponentLocation(), mc->GetComponentLocation(), 500.f,
		ObjectTypesArray, true, ignored, EDrawDebugTrace::ForDuration, hits, true);

	std::vector<UGrabComponent*> grabs;
	for (auto& hit : hits) {
		auto actor = hit.GetActor();

		//Check if its has a grab component
		auto comps = actor->GetComponentsByClass(UGrabComponent::StaticClass());
		for (auto& comp : comps) {
			UGrabComponent* grab = Cast<UGrabComponent>(comp);
			if (grab) {
				grabs.push_back(grab);
			}
		}
	}
	
	return grabs;
}

UGrabComponent* AVRPlayer::GetGrabbed(UMotionControllerComponent* mc)
{
	return mGrabs[mc];
}

bool AVRPlayer::GrabbingItem(UMotionControllerComponent* mc)
{
	if (GetGrabbed(mc)) {
		return true;
	}
	else {
		return false;
	}
}

#pragma endregion