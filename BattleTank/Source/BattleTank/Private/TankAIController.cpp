// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	auto PlayerTank=Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());

	Super::Tick(DeltaTime);
	if (PlayerTank)
	{
		AITank->AimAt(PlayerTank->GetActorLocation());
		AITank->Fire();
	}
}
