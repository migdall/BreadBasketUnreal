// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseRandomCube.h"

// Sets default values for this component's properties
UChooseRandomCube::UChooseRandomCube()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UChooseRandomCube::BeginPlay()
{
	Super::BeginPlay();

	// Log hello world
	UE_LOG(LogTemp, Warning, TEXT("Hello, World!"));

	// ...
	
}


// Called every frame
void UChooseRandomCube::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

