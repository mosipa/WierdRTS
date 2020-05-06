// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UnitController.generated.h"

/**
 * 
 */
UCLASS()
class WIERDRTS_API AUnitController : public AAIController
{
	GENERATED_BODY()
	
private:
	AUnitController();

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UActionReceiverComponent* ActionReceiverComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Blackboard")
	class UBlackboardData* BlackboardData;

	virtual void OnPossess(class APawn* InPawn) override;
};
