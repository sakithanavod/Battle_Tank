// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp,Error,TEXT("AI Controller cant find Player"))
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Found Player %s"),*(PlayerTank->GetName()))
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}


ATank*ATankAIController::GetAIControlledTanks() const 
{
	return Cast<ATank>(GetPawn());
}

