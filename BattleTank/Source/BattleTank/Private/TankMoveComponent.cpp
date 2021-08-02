// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "TankMoveComponent.h"

void UTankMoveComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMoveComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward %f"), Throw);
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMoveComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}
