// Fill out your copyright notice in the Description page of Project Settings.


#include "WierdRTS/Public/Components/ActionReceiverComponent.h"
#include "AIController.h" 	
#include "BehaviorTree/BlackboardComponent.h"

// Sets default values for this component's properties
UActionReceiverComponent::UActionReceiverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	AIController = Cast<AAIController>(GetOwner());

	// ...
}


// Called when the game starts
void UActionReceiverComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}


void UActionReceiverComponent::RequestSelect(bool bShouldSelect)
{
	if (AIController)
	{
		AIController->GetBlackboardComponent()->SetValueAsBool("bSelected", bShouldSelect);
		OnRequestSelect.Broadcast(bShouldSelect); 
		bUnitSelected = bShouldSelect;
	}
}


// Called every frame
void UActionReceiverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}

