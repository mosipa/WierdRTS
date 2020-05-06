// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WierdRTSPlayerController.generated.h"

UCLASS()
class AWierdRTSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AWierdRTSPlayerController();

	void BeginPlay() override;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	UPROPERTY(VisibleDefaultsOnly, Category = "Setup - Components")
	class UUnitManagerComponent* UnitManagerComponent;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	void SelectUnits();
	void StopSelecting();

	void UnselectUnits();
	void StopCamera();

	UFUNCTION()
	void MoveCamera();

	virtual void OnPossess(APawn* InPawn) override;

private:
	FTimerHandle MoveCameraTimer;
	FVector2D PreviousCursorLocation;

	APawn* ControlledPawn;
	class APlayersHUD* HUD;
};


