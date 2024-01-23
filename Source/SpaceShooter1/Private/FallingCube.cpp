// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingCube.h"

// Sets default values
AFallingCube::AFallingCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize the cube mesh component and attach it to the actor's root
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	RootComponent = CubeMesh;

	// Load a cube mesh (Replace 'CubeMeshPath' with the actual path to your mesh)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshObj(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (CubeMeshObj.Succeeded())
	{
		CubeMesh->SetStaticMesh(CubeMeshObj.Object);
	}

	// Initialize properties
	FallingSpeed = 400.0f; // Adjust this value as needed
	StartPosition = FVector(0.0f, 0.0f, 500.0f); // Adjust the starting position as needed
	EndZ = -5.0f; // Adjust the end position as needed

}

// Called when the game starts or when spawned
void AFallingCube::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(StartPosition);
	
}

// Called every frame
void AFallingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Update the cube's position
	FVector NewLocation = GetActorLocation();
	NewLocation.Z -= FallingSpeed * DeltaTime;
	SetActorLocation(NewLocation);

	// Check for respawn
	CheckRespawn();

}

void AFallingCube::CheckRespawn()
{
	if (GetActorLocation().Z < EndZ) // Assuming 0 is the ground level; adjust as needed
	{
		SetActorLocation(StartPosition);
	}
}
