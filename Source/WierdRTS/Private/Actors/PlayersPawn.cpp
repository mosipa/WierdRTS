// Fill out your copyright notice in the Description page of Project Settings.


#include "WierdRTS/Public/Actors/PlayersPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneCaptureComponent2D.h"

// Sets default values
APlayersPawn::APlayersPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	PlayersCamera = CreateDefaultSubobject<UCameraComponent>("PlayersCamera");
	PlayersCamera->SetWorldRotation(FRotator(-90.f, 0.f, 0.f));
	PlayersCamera->AttachToComponent(Root, FAttachmentTransformRules::KeepWorldTransform);

	MiniMapsSpringArm = CreateDefaultSubobject<USpringArmComponent>("MiniMapsSpringArm");
	MiniMapsSpringArm->SetWorldLocation(FVector(-300.f, 0.f, 0.f));
	MiniMapsSpringArm->AttachToComponent(PlayersCamera, FAttachmentTransformRules::KeepWorldTransform);

	MiniMapsSceneCaptureComponent = CreateDefaultSubobject<USceneCaptureComponent2D>("MiniMapsSceneCaptureComponent");
	MiniMapsSceneCaptureComponent->AttachToComponent(MiniMapsSpringArm, FAttachmentTransformRules::SnapToTargetIncludingScale);
}

// Called when the game starts or when spawned
void APlayersPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayersPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayersPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

