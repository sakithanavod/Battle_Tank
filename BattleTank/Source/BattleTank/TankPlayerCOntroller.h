// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerCOntroller.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerCOntroller : public APlayerController
{
	GENERATED_BODY()

public:
	ATank*GetControlledTank() const;
	virtual void BeginPlay() override;

};
