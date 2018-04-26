// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerCOntroller.h"
#include "Tank.h"

void ATankPlayerCOntroller::BeginPlay()
{
	Super::BeginPlay();
	
	auto PossedPawn = GetControlledTank();

	if (!PossedPawn) 
	{ 
		UE_LOG(LogTemp, Error, TEXT("Player Controller Not Possing Pawn")) 
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Possed Tank Name %s"), *(PossedPawn->GetName()))
	}
}

void ATankPlayerCOntroller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}


ATank * ATankPlayerCOntroller::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); //treat pawn as a TANK
}

void ATankPlayerCOntroller::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation; //out paramiter
	if (GetSightRayHitLocation(HitLocation)) 
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerCOntroller::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	FVector WorldDirection;

	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto FindScreenLocation = FVector2D((CrosshairXLocation * ViewportSizeX), (CrosshairYLocation * ViewportSizeY));
	if (GetLookDirection(FindScreenLocation, WorldDirection)) 
	{
		GetVectorLookHitLocation(WorldDirection, HitLocation);
	}
	return true;
}

bool ATankPlayerCOntroller::GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirection) const
{
	FVector WorldCameraLocationTemp;

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldCameraLocationTemp, WorldDirection);
}

bool ATankPlayerCOntroller::GetVectorLookHitLocation(FVector WorldDirection, FVector& HitLocation) const
{

	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (WorldDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, 
		StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation=HitResult.Location;
	return true;
	}
	HitLocation = FVector(0.0f);
	return false; // no hit
}