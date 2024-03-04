// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlateform.generated.h"

UCLASS()
class OBSTACLE_API AMovingPlateform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlateform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/* UPROPERTY(Editanywhere)
	int32 MyInt = 99;
	UPROPERTY(EditAnywhere)
	int32 InputA = 0;

	UPROPERTY(EditAnywhere)
	int32 InputB = 0;

	UPROPERTY(EditAnywhere)
	int32 AplusB = 0;*/
	/*UPROPERTY(EditAnywhere)
	FVector MyVector = FVector(1,2,3);

	UPROPERTY(EditAnywhere)
	float MyX=0;*/
	private:
	UPROPERTY(EditAnywhere,Category = "Moving")
	FVector PlateformVelocity = FVector(100,0,0);
	UPROPERTY(VisibleAnywhere)
	float DistanceMoved = -1;

	UPROPERTY(EditAnywhere,Category = "Moving")
	float MoveDistance = 100;
	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;


	FVector StartLocation; 
	void MovePlateform(float DeltaTime);
	void RotatePlateform(float DeltaTime);

	bool ShouldPlateformReturn()const;
	float GetDistanceMoved()const;



};
