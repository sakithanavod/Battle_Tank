// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponet.h"
#include "TankBarrel.h"
#include "TankTurret.h"


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
		StartLocation, HitLocation, LaunchSpeed,false,0,0, ESuggestProjVelocityTraceOption::DoNotTrace);
	
	if (bHaveAimSolution) {//calculation sucess

		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankNames = GetOwner()->GetName();
		MoveBarrel(AimDirection);

		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);
	}
}

void UTankAimComponet::MoveBarrel(FVector Direction)
{
	//get the aim direction and covert it in to rotators
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotation = Direction.Rotation();
	FRotator DeltaRotation = AimAsRotation - BarrelRotator;

	if (!Barrel) { return; }
	Barrel->Elevate(DeltaRotation.Pitch);

	if (!Turret) { return; }
	Turret->Rotate(DeltaRotation.Yaw);
	
}


void UTankAimComponet::SetBarrelRefereance(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet; 
}

void UTankAimComponet::SetTurretRefereance(UTankTurret *TurretToSet)
{
	Turret = TurretToSet;
}

