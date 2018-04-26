// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; //forward declaration
class UTankAimComponet;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelRefereance(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretRefereance(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Projectile)  
	void Fire();

	UPROPERTY(Editanywhere, Category = Setup)
	TSubclassOf<AProjectile>ProjectileBlueprint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimComponet*TankAimingComponet = nullptr;

private:	

	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category= Firing)
	float LaunchSpeed = 4000.0f;

	UTankBarrel*Barrel = nullptr; // local barrel referance
	
	
};
