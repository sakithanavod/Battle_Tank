// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankNew.generated.h"

UCLASS()
class BATTLETANK_API ATankNew : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankNew();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTurretChildActor(UChildActorComponent *TurretFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetBarrelChildActor(UChildActorComponent *BarrelFromBP);
	
	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTankChildActor(UChildActorComponent * TankFromBP);

	

private:
	//rotate turret at speed of
	void RotateTurret(float Speed);
	void RotateBarrel(float Speed);

	//Tank Move methods
	void MoveTank(float Speed);
	void RotateTank(float Speed);

	//A referances from blueprint
	UChildActorComponent*Turret=nullptr;
	UChildActorComponent*Barrel = nullptr;
	UChildActorComponent*Tank = nullptr;

	UPROPERTY(EditAnywhere)
	float RotationSpeed = 60.0f;

	UPROPERTY(EditAnywhere)
	float MovementSpeed = 60.0f;
};
