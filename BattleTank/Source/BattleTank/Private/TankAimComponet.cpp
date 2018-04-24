// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponet.h"


// Sets default values for this component's properties
UTankAimComponet::UTankAimComponet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimComponet::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this, OutLaunchVelocity,
		StartLocation, HitLocation, LaunchSpeed, ESuggestProjVelocityTraceOption::DoNotTrace);
	
	if (bHaveAimSolution) {//calculation sucess

		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankNames = GetOwner()->GetName();
		MoveBarrel(AimDirection);
	}
	//else nothing
}

void UTankAimComponet::MoveBarrel(FVector Direction)
{
	//get the aim direction and covert it in to rotators
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotation = Direction.Rotation();
	FRotator DeltaRotation = AimAsRotation - BarrelRotator;

	UE_LOG(LogTemp, Warning, TEXT("Aim Direction %s"), *DeltaRotation.ToString());
	// according those rotators change posion of the barrel
	
}

void UTankAimComponet::SetBarrelRefereance(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet; 
}

