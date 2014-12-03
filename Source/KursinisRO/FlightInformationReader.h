// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "FlightInformationReader.generated.h"

/**
 * 
 */
UCLASS()
class KURSINISRO_API UFlightInformationReader : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "FlightInformation")
	static TArray<FVector> GetFlightCoordinates(FString FileLocation);

	UFUNCTION(BlueprintCallable, Category = "FlightInformation")
	static FString ReadFile(FString FileLocation, int32 selector);
	
};
