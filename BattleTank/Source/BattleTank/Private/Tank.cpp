// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimComponet.h"
#include "TankTurret.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponet = CreateDefaultSubobject<UTankAimComponet>(FName("Aiming Componet"));
}

void ATank::SetBarrelRefereance(UTankBarrel * BarrelToSet)
{
	TankAimingComponet->SetBarrelRefereance(BarrelToSet);
}

void ATank::SetTurretRefereance(UTankTurret* TurretToSet)
{
	TankAimingComponet->SetTurretRefereance(TurretToSet);
}

void ATank::Fire()
{
	UE_LOG(LogTemp,Warning,TEXT("Tank is firing"))
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation) 
{
	TankAimingComponet->AimAt(HitLocation, LaunchSpeed);
	
}