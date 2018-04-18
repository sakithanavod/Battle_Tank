// Fill out your copyright notice in the Description page of Project Settings.

#include "TankNew.h"


// Sets default values
ATankNew::ATankNew()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATankNew::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankNew::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATankNew::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Rotate_Turret", this, &ATankNew::RotateTurret);
	PlayerInputComponent->BindAxis("Rotate_Barrel", this, &ATankNew::RotateBarrel);
}

void ATankNew::RotateTurret(float Speed)
{
	if (!Turret) { return; }
	Turret->AddRelativeRotation(FRotator(0.0f,Speed,0.0f));
}

void ATankNew::RotateBarrel(float Speed)
{
	if (!Barrel) { return; }
	Barrel->AddRelativeRotation(FRotator(Speed,0.0f,0.0f));
}

void ATankNew::SetTurretChildActor(UChildActorComponent * TurretFromBP)
{
	Turret = TurretFromBP;
}

void ATankNew::SetBarrelChildActor(UChildActorComponent * BarrelFromBP)
{
	Barrel = BarrelFromBP;
}
