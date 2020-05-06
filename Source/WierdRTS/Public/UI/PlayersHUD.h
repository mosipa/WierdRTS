// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayersHUD.generated.h"

/**
 * 
 */
UCLASS()
class WIERDRTS_API APlayersHUD : public AHUD
{
	GENERATED_BODY()
	
private:
	class UUnitManagerComponent* OwnersUnitManagerComponent;

protected:
	FVector2D InitialPoint;
	FVector2D CurrentPoint;

	bool bStartSelecting = false;

public:
	virtual void BeginPlay() override;

	FVector2D GetMousePosition2D();

	virtual void DrawHUD() override;

	void SetInitialPoint(FVector2D NewInitialPoint);

	void SetSelecting(bool bNewSelecting);
};
