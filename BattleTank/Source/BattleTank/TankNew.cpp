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
	PlayerInputComponent->BindAxis("Move_Tank", this, &ATankNew::MoveTank);
	PlayerInputComponent->BindAxis("Rotate_Tank", this, &ATankNew::RotateTank);
}

void ATankNew::MoveTank(float Speed)
{
	if (!Tank) { return; }
	float Distance = GetWorld()->DeltaTimeSeconds*Speed*MovementSpeed; //Using deltatime for make framerate independent
	Tank->AddRelativeLocation(Tank->GetForwardVector()*Distance);
}

void ATankNew::RotateTank(float Speed)
{
	if (!Tank) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds*Speed*RotationSpeed;
	Tank->AddRelativeRotation(FRotator(0.0f, Rotation, 0.0f));
}

void ATankNew::RotateTurret(float Speed)
{
	if (!Turret) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds*Speed*RotationSpeed;
	Turret->AddRelativeRotation(FRotator(0.0f,Rotation,0.0f));
}

void ATankNew::RotateBarrel(float Speed)
{
	if (!Barrel) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds*Speed*RotationSpeed;
	Barrel->AddRelativeRotation(FRotator(Rotation,0.0f,0.0f));
}

void ATankNew::SetTankChildActor(UChildActorComponent * TankFromBP)
{
	if (!TankFromBP) { return; }
	Tank = TankFromBP;
}

void ATankNew::SetTurretChildActor(UChildActorComponent * TurretFromBP)
{
	if (!TurretFromBP) { return; }
	Turret = TurretFromBP;
}

void ATankNew::SetBarrelChildActor(UChildActorComponent * BarrelFromBP)
{
	if (!BarrelFromBP) { return; }
	Barrel = BarrelFromBP; 
}
