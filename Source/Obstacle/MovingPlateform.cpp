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

		//AplusB = InputA+InputB;
		StartLocation = GetActorLocation();
		//UE_LOG(LogTemp,Display,TEXT("Configure Moved Distance :  %f"),MoveDistance);
		FString Name = GetName();

	 UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *Name);

}

// Called every frame
void AMovingPlateform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + PlateformVelocity * DeltaTime;

	SetActorLocation(CurrentLocation);

	/*MyVector.X = MyVector.X + 5 ;
	SetActorLocation(MyVector);*/

	DistanceMoved = FVector::Dist(StartLocation,CurrentLocation);

	if(DistanceMoved > MoveDistance)
	{
		float OverShoot = DistanceMoved-MoveDistance;
		//UE_LOG(LogTemp,Display,TEXT("Pateform Overshot by %f"),OverShoot);
		FString Name = GetName();
		UE_LOG(LogTemp, Display, TEXT("%s Plateform overshot by %f"), *Name, OverShoot);


		FVector MoveDirection = PlateformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlateformVelocity = -PlateformVelocity;

	}
}


