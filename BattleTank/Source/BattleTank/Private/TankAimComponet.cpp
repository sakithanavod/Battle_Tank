// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponet.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"


// Sets default values for this component's properties
UTankAimComponet::UTankAimComponet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimComponet::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel)) { return; }
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

	if (!ensure(Barrel)) { return; }
	Barrel->Elevate(DeltaRotation.Pitch);

	if (!ensure(Turret)) { return; }
	Turret->Rotate(DeltaRotation.Yaw);
	
}


void UTankAimComponet::SetAimComponents(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	Barrel = BarrelToSet; 
	Turret = TurretToSet;
}

void UTankAimComponet::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel&&isReloaded)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Tank is firing"))
		auto ProjectileLocation = Barrel->GetSocketLocation(FName("Projectile"));
		auto ProjectileRotation = Barrel->GetSocketRotation(FName("Projectile"));

		if (!ensure(ProjectileBlueprint)) {
			UE_LOG(LogTemp, Error, TEXT("Set Projectile BP in Tnak BP"))
				return;
		}
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, ProjectileLocation, ProjectileRotation);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
