// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Constructable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UConstructable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WIERDRTS_API IConstructable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Construction")
	bool Construction();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Construction")
	bool Deletion();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Construction")
	bool CheckResources();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Construction")
	bool PreConstruction();
};
