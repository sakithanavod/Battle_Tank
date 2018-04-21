// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerCOntroller.h"


void ATankPlayerCOntroller::BeginPlay()
{
	Super::BeginPlay();
	
	auto PossedPawn = GetControlledTank();

	if (!PossedPawn) 
	{ 
		UE_LOG(LogTemp, Error, TEXT("Player Controller Not Possing Pawn")) 
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Possed Tank Name %s"), *(PossedPawn->GetName()))
	}
}


ATank * ATankPlayerCOntroller::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

