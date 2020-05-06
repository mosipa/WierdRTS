// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WierdRTS/Public/Interfaces/Constructable.h"
#include "GameFramework/Actor.h"
#include "BasicBuilding.generated.h"

UCLASS()
class WIERDRTS_API ABasicBuilding : public AActor, public IConstructable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicBuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMesh* BuildingMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMesh* PreBuildingMesh;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float RequiredTime;

	//TODO add struct which will contain resources required for constructing building
	UPROPERTY(EditAnywhere, Category = "Setup")
	float Cost;

	UFUNCTION(BlueprintCallable, Category = "Construct")
	virtual void ConstructBuilding();

	UFUNCTION(BlueprintCallable, Category = "Construct")
	virtual void PreconstructBuilding();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Construction")
	bool Construction();
	virtual bool Construction_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Construction")
	bool Deletion();
	virtual bool Deletion_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Construction")
	bool CheckResources();
	virtual bool CheckResources_Implementation() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Construction")
	bool PreConstruction();
	virtual bool PreConstruction_Implementation() override;
};
