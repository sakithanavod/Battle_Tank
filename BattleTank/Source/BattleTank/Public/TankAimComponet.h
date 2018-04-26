// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Components/ActorComponent.h"
#include "TankAimComponet.generated.h"

//forward declaration
class UTankBarrel; 
class UTankTurret;

//hold barrel propertise
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimComponet : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponet();
	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelRefereance(UTankBarrel * BarrelToSet);
	void SetTurretRefereance(UTankTurret * TurretToSet);

protected:


private:
	UTankBarrel * Barrel = nullptr;
	UTankTurret * Turret = nullptr;
	void MoveBarrel(FVector Direction);
		
	
};
