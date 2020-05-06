// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UnitManagerComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WIERDRTS_API UUnitManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUnitManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddUnitToSelection(class ACharacter* UnitToAdd);
	void RemoveUnitFromSelection(class ACharacter* UnitToRemove);
	void RemoveAllUnits();
	int32 GetNumOfSelectedUnits() const;

private:
	TArray<class ACharacter*> SelectedUnits;
};
