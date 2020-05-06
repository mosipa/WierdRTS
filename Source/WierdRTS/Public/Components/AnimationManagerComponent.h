// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimationManagerComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSelected, bool, bSelected);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WIERDRTS_API UAnimationManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAnimationManagerComponent();

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnSelected OnSelected;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
