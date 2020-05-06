// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayersPawn.generated.h"

UCLASS()
class WIERDRTS_API APlayersPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayersPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Setup - Components")
	class UCameraComponent* PlayersCamera;

	UPROPERTY(VisibleDefaultsOnly, Category = "Setup - Components")
	class USceneComponent* Root;

	//MiniMap setup
	UPROPERTY(VisibleDefaultsOnly, Category = "Setup - Components")
	class USpringArmComponent* MiniMapsSpringArm;

	UPROPERTY(VisibleDefaultsOnly, Category = "Setup - Components")
	class USceneCaptureComponent2D* MiniMapsSceneCaptureComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
