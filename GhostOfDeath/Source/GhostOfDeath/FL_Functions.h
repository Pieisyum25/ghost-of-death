// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FL_Functions.generated.h"


/**
 * 
 */
UCLASS()
class GHOSTOFDEATH_API UFL_Functions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		
	UFUNCTION(BlueprintCallable, Category = "CustomFunctions")
		static FVector GetBobbingLocation(float timeSinceStart, float bobbingSpeed, float bobbingHeight);
	
	UFUNCTION(BlueprintCallable, Category = "CustomFunctions")
		static FVector FlipScaleWithMovement(FVector velocity, FVector originalScale);
	
	UFUNCTION(BlueprintCallable, Category = "CustomFunctions")
		static FVector GetUnitDirectionXZ(FVector from, FVector to);
};
