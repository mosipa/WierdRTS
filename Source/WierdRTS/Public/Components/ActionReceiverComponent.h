// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActionReceiverComponent.generated.h"

UENUM()
enum Behavior
{
	Idle     UMETA(DisplayName = "Idle"),
	Moving      UMETA(DisplayName = "Moving")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestSelect, bool, bSelect);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WIERDRTS_API UActionReceiverComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActionReceiverComponent();

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnRequestSelect OnRequestSelect;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void RequestSelect(bool bShouldSelect);

private:
	bool bUnitSelected = false;

	class AAIController* AIController = nullptr;
};
