// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "TankMoveComponent.h"

void UTankMoveComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	UE_LOG(LogTemp, Warning, TEXT("Track set"));
	if (!LeftTrack || !RightTrack)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Track"));
		return;
	}
}

void UTankMoveComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("No Track"));
		return; 
	}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMoveComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	//UE_LOG(LogTemp, Warning, TEXT("%f"), Throw);
}

void UTankMoveComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super as we're replacing the functionality
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);

	auto RightThrottle = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(RightThrottle);
	
}
