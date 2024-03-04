// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlateform.h"

// Sets default values
AMovingPlateform::AMovingPlateform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlateform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	FString Name = GetName();

	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *Name);
}

// Called every frame
void AMovingPlateform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlateform(DeltaTime);
	RotatePlateform(DeltaTime);
}


void AMovingPlateform::MovePlateform(float DeltaTime)
{
	if (ShouldPlateformReturn())
	{
		FVector MoveDirection = PlateformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlateformVelocity = -PlateformVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlateformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlateform::RotatePlateform(float DeltaTime)
{
FRotator CurrentRotation = GetActorRotation();
	CurrentRotation = CurrentRotation + RotationVelocity * DeltaTime;
	SetActorRotation(CurrentRotation);
}


bool AMovingPlateform::ShouldPlateformReturn()const
{
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlateform::GetDistanceMoved()const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

