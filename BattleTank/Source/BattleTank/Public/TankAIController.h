// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "Engine.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank*GetAIControlledTanks() const;
	virtual void BeginPlay() override;
	ATank*GetPlayerTank() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};