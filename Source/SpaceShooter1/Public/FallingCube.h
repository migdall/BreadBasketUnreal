// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "FallingCube.generated.h"

UCLASS()
class SPACESHOOTER1_API AFallingCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFallingCube();

	UPROPERTY(EditAnywhere, Category = "Movement")
	float FallingSpeed;

	UPROPERTY(EditAnywhere, Category = "Position")
	FVector StartPosition;

	UPROPERTY(EditAnywhere, Category = "Position")
	float EndZ;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void CheckRespawn();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CubeMesh;

};
