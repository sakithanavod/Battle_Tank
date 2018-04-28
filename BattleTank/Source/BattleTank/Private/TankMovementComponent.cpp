// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "Tank.h"




void UTankMovementComponent::SetTracks(UTankTrack * LeftTrack, UTankTrack * RightTrack)
{
	if (!(LeftTrack || RightTrack)) { UE_LOG(LogTemp, Error, TEXT("Error")) return; }
	SetLeftTrack = LeftTrack;
	SetRightTrack = RightTrack;

}

void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	if (!(SetLeftTrack || SetRightTrack)) { UE_LOG(LogTemp, Error, TEXT("Error")) return; }
	SetLeftTrack->SetThrottle(Throw);
	SetRightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!(SetLeftTrack || SetRightTrack)) { UE_LOG(LogTemp, Error, TEXT("Error")) return; }
	SetLeftTrack->SetThrottle(Throw);
	SetRightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();
	
	UE_LOG(LogTemp, Warning, TEXT("%s has move velocity of: %s"), *TankName, *MoveVelocityString)
}

