// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Components/ActorComponent.h"
#include "TankAimComponet.generated.h"

//enummator for target states
UENUM()
enum class EFiringState :uint8 
{
Reloading,
Aiming,
Locked
};

//forward declaration
class UTankBarrel; 
class UTankTurret;
class AProjectile;

//hold barrel propertise
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimComponet : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponet();
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Projectile)
	void Fire();

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile>ProjectileBlueprint;

	

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Locked;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetAimComponents(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet);

private:
	UTankBarrel * Barrel = nullptr;
	UTankTurret * Turret = nullptr;
	void MoveBarrel(FVector Direction);

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000.0f;

	double LastFireTime = 0;

};
