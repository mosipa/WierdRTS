// Fill out your copyright notice in the Description page of Project Settings.

#include "WierdRTS/Public/Actors/BasicBuilding.h"
#include "Engine/StaticMesh.h"

// Sets default values
ABasicBuilding::ABasicBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BuildingMesh = CreateDefaultSubobject<UStaticMesh>("BuildingMesh");
	PreBuildingMesh = CreateDefaultSubobject<UStaticMesh>("PreBuildingMesh");

	SetRootComponent(Cast<USceneComponent>(PreBuildingMesh));
}

// Called when the game starts or when spawned
void ABasicBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasicBuilding::ConstructBuilding()
{

}

void ABasicBuilding::PreconstructBuilding()
{

}


bool ABasicBuilding::Construction_Implementation()
{
	return true;
}


bool ABasicBuilding::Deletion_Implementation()
{
	return true;
}


bool ABasicBuilding::CheckResources_Implementation()
{
	return true;
}


bool ABasicBuilding::PreConstruction_Implementation()
{
	return true;
}