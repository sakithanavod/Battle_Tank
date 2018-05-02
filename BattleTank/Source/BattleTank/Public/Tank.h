// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; //forward declaration
class UTankTurret;



UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

private:	

	// Sets default values for this pawn's properties
	ATank();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
};
