// Fill out your copyright notice in the Description page of Project Settings.


#include "WierdRTS/Public/Actors/ControllableUnit.h"
#include "WierdRTS/Public/Components/AnimationManagerComponent.h"

// Sets default values
AControllableUnit::AControllableUnit()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AnimationManagerComponent = CreateDefaultSubobject<UAnimationManagerComponent>("AnimationManagerComponent");

}

// Called when the game starts or when spawned
void AControllableUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControllableUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AControllableUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

