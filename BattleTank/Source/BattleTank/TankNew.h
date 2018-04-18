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

private:
	//rotate turret at speed of
	void RotateTurret(float Speed);
	void RotateBarrel(float Speed);

	//A referance from blueprint
	UChildActorComponent*Turret=nullptr;
	UChildActorComponent*Barrel = nullptr;
};
