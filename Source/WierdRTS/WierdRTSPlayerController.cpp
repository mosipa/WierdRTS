// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "WierdRTSPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "WierdRTSCharacter.h"
#include "Engine/World.h"
#include "WierdRTS/Public/UI/PlayersHUD.h"
#include "Camera/CameraComponent.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "DrawDebugHelpers.h"
#include "WierdRTS/Public/Components/UnitManagerComponent.h"

AWierdRTSPlayerController::AWierdRTSPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;

	UnitManagerComponent = CreateDefaultSubobject<UUnitManagerComponent>("UnitManagerComponent");
}

void AWierdRTSPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void AWierdRTSPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	ControlledPawn = InPawn;
}

void AWierdRTSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = Cast<APlayersHUD>(GetHUD());
}

void AWierdRTSPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("LMBActions", IE_Pressed, this, &AWierdRTSPlayerController::SelectUnits);
	InputComponent->BindAction("StopSelecting", IE_Released, this, &AWierdRTSPlayerController::StopSelecting);
	InputComponent->BindAction("RMBActions", IE_Pressed, this, &AWierdRTSPlayerController::UnselectUnits);
	InputComponent->BindAction("StopCamera", IE_Released, this, &AWierdRTSPlayerController::StopCamera);
}

void AWierdRTSPlayerController::SelectUnits()
{
	if (!HUD || !UnitManagerComponent)
	{
		return;
	}

	if (UnitManagerComponent->GetNumOfSelectedUnits() == 0)
	{
		HUD->SetInitialPoint(HUD->GetMousePosition2D());
		HUD->SetSelecting(true);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Request to do something"));
	}
	/*
	else
	{
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);
		if (Hit.IsValidBlockingHit())
		{
			for (ACharacter*& Actor : SelectedActors)
			{
				Actor->SetActorLocation(Hit.Location);
			}
		}
	}*/
}

void AWierdRTSPlayerController::StopSelecting()
{
	if (!HUD)
	{
		return;
	}

	HUD->SetSelecting(false);
}


void AWierdRTSPlayerController::UnselectUnits()
{
	if (!HUD || !UnitManagerComponent)
	{
		return;
	}

	if (UnitManagerComponent->GetNumOfSelectedUnits() > 0)
	{
		UnitManagerComponent->RemoveAllUnits();
	}
	else
	{
		GetWorld()->GetTimerManager().SetTimer(MoveCameraTimer, this, &AWierdRTSPlayerController::MoveCamera, GetWorld()->GetDeltaSeconds(), true);
	}
}

void AWierdRTSPlayerController::MoveCamera()
{
	if (!ControlledPawn || !HUD)
	{
		return;
	}

	FVector2D ViewportSize;
	int32 XSize; int32 YSize;
	GetViewportSize(XSize, YSize);
	FVector2D CursorPosition = HUD->GetMousePosition2D();
	CursorPosition.X -= float(XSize / 2);
	CursorPosition.Y -= float(YSize / 2);

	if (PreviousCursorLocation.Equals(FVector2D::ZeroVector))
	{
		PreviousCursorLocation = CursorPosition;
	}

	float DiffX = PreviousCursorLocation.X - CursorPosition.X;
	float DiffY = PreviousCursorLocation.Y - CursorPosition.Y;
	FVector PrevLocation = ControlledPawn->GetActorLocation();
	FVector CameraPosition = FVector(PrevLocation.X - DiffY / 2.f, PrevLocation.Y + DiffX / 2.f, PrevLocation.Z);
	ControlledPawn->SetActorLocation(CameraPosition);
	
	PreviousCursorLocation = CursorPosition;
}

void AWierdRTSPlayerController::StopCamera()
{
	if (MoveCameraTimer.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(MoveCameraTimer); 
		PreviousCursorLocation = FVector2D::ZeroVector;
	}
}

/*
void AWierdRTSPlayerController::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (AWierdRTSCharacter* MyPawn = Cast<AWierdRTSCharacter>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}

void AWierdRTSPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AWierdRTSPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AWierdRTSPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AWierdRTSPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
*/