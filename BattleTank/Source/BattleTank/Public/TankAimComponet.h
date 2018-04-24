// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Components/ActorComponent.h"
#include "TankAimComponet.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimComponet : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponet();
	void AimAt(FVector HitLocation, float LaunchSpeed);
	// Called every frame
	void SetBarrelRefereance(UStaticMeshComponent * BarrelToSet);


protected:


private:
	UStaticMeshComponent * Barrel = nullptr;
	void MoveBarrel(FVector Direction);
		
	
};
