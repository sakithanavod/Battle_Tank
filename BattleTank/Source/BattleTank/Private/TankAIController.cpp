// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimComponet.h"

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	auto PlayerTank=GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();

	Super::Tick(DeltaTime);
	if (!ensure(PlayerTank&&AITank)) { return; }
	else {
		MoveToActor(PlayerTank, AcceptenceRadius);

		auto AimingComponent = AITank->FindComponentByClass<UTankAimComponet>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		//AimingComponent->Fire();
	}
}
