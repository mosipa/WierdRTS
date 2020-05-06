// Fill out your copyright notice in the Description page of Project Settings.


#include "WierdRTS/Public/Components/UnitManagerComponent.h"
#include "GameFramework/Character.h"
#include "WierdRTS/Public/Components/ActionReceiverComponent.h"

// Sets default values for this component's properties
UUnitManagerComponent::UUnitManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UUnitManagerComponent::AddUnitToSelection(ACharacter* UnitToAdd)
{
	if (UnitToAdd)
	{
		UActionReceiverComponent* SelectedUnitActionReceiverComponent = UnitToAdd->GetController()->FindComponentByClass<UActionReceiverComponent>();
		if (SelectedUnitActionReceiverComponent)
		{
			SelectedUnitActionReceiverComponent->RequestSelect(true);
			SelectedUnits.AddUnique(UnitToAdd);
		}
	}
}


int32 UUnitManagerComponent::GetNumOfSelectedUnits() const
{
	return SelectedUnits.Num();
}

void UUnitManagerComponent::RemoveUnitFromSelection(ACharacter* UnitToRemove)
{
	if (UnitToRemove && SelectedUnits.Find(UnitToRemove))
	{
		SelectedUnits.RemoveSingle(UnitToRemove);
	}
}


void UUnitManagerComponent::RemoveAllUnits()
{
	if (SelectedUnits.Num() > 0)
	{
		for (auto& Unit : SelectedUnits)
		{
			UActionReceiverComponent* SelectedUnitActionReceiverComponent = Unit->GetController()->FindComponentByClass<UActionReceiverComponent>();
			if (SelectedUnitActionReceiverComponent)
			{
				SelectedUnitActionReceiverComponent->RequestSelect(false);
			}
		}

		SelectedUnits.Empty();
	}
}

// Called when the game starts
void UUnitManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UUnitManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

