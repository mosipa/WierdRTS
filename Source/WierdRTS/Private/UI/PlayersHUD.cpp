// Fill out your copyright notice in the Description page of Project Settings.


#include "WierdRTS/Public/UI/PlayersHUD.h"
#include "WierdRTS/WierdRTSPlayerController.h"
#include "GameFramework/Character.h"
#include "WierdRTS/Public/Components/UnitManagerComponent.h"
#include "GameFramework/PlayerController.h"

void APlayersHUD::BeginPlay()
{
	Super::BeginPlay();
	
	if (PlayerOwner)
	{
		OwnersUnitManagerComponent = PlayerOwner->FindComponentByClass<UUnitManagerComponent>();
	}
}


void APlayersHUD::DrawHUD()
{
	if (!OwnersUnitManagerComponent)
	{
		return;
	}

	if (bStartSelecting)
	{
		if (OwnersUnitManagerComponent->GetNumOfSelectedUnits() > 0)
		{
			OwnersUnitManagerComponent->RemoveAllUnits();
		}

		CurrentPoint = GetMousePosition2D();

		DrawRect(FLinearColor(0.f, 0.f, 1.f, 0.10f), InitialPoint.X, InitialPoint.Y,
			CurrentPoint.X - InitialPoint.X, CurrentPoint.Y - InitialPoint.Y);

		TArray<ACharacter*> ActorsToSelect;
		GetActorsInSelectionRectangle<ACharacter>(InitialPoint, CurrentPoint, ActorsToSelect, false, false);

		//Only select actors that aren't dead
		for (auto Character : ActorsToSelect)
		{
			OwnersUnitManagerComponent->AddUnitToSelection(Character);
		}
	}
}


FVector2D APlayersHUD::GetMousePosition2D()
{
	float PosX;
	float PosY;

	GetOwningPlayerController()->GetMousePosition(PosX, PosY);

	return FVector2D(PosX, PosY);
}


void APlayersHUD::SetInitialPoint(FVector2D NewInitialPoint)
{
	InitialPoint = NewInitialPoint;
}


void APlayersHUD::SetSelecting(bool bNewSelecting)
{
	bStartSelecting = bNewSelecting;
}