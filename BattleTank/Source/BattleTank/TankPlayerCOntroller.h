// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerCOntroller.generated.h"

class ATank;

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
	virtual void Tick(float DeltaTime) override;

private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;                                   
	bool GetLookDirection(FVector2D ScreenLocation, FVector & WorldDirection) const;
	bool GetVectorLookHitLocation(FVector WorldDirection, FVector& HitLocation) const;
	//Change Barrel posision to crosshair

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333333f;

	float LineTraceRange = 100000.0f;
};
