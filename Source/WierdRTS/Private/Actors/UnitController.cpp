// Fill out your copyright notice in the Description page of Project Settings.


#include "WierdRTS/Public/Actors/UnitController.h"
#include "WierdRTS/Public/Components/ActionReceiverComponent.h" 	
#include "BehaviorTree/BehaviorTree.h" 	
#include "BehaviorTree/BlackboardData.h"

AUnitController::AUnitController()
{
	ActionReceiverComponent = CreateDefaultSubobject<UActionReceiverComponent>("ActionReceiverComponent");
}

void AUnitController::OnPossess(class APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (!BehaviorTree)
	{
		return;
	}

	//Can initialize anything that's needed for AI Controller

	UBlackboardComponent* BlackboardComponent = GetBlackboardComponent();
	UseBlackboard(BlackboardData, BlackboardComponent);
	RunBehaviorTree(BehaviorTree);
}