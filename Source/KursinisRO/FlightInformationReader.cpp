// Fill out your copyright notice in the Description page of Project Settings.

#include "KursinisRO.h"
#include "FlightInformationReader.h"


UFlightInformationReader::UFlightInformationReader(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}
	
TArray<FVector> UFlightInformationReader::GetFlightCoordinates(FString FileLocation) {
	TArray<FVector> points;
	FString rawData;
	FFileHelper::LoadFileToString(rawData, *FileLocation);

	TArray<FString> parsedData;
	const TCHAR* Delims[] = { TEXT(","), TEXT("\n")};
	rawData.ParseIntoArray(&parsedData, Delims, 2);

	int32 i = 7;

	while (i + 2 < parsedData.Num()) {
		points.Add(FVector((FCString::Atof(*parsedData[i]) - 100) * 1852, (FCString::Atof(*parsedData[i + 1]) + 50) * 1852, FCString::Atof(*parsedData[i + 2]) * 0.3048));
		i += 5;
	}
	return points;
}

FString UFlightInformationReader::ReadFile(FString FileLocation, int32 selector) {
	FString rawData;
	FFileHelper::LoadFileToString(rawData, *FileLocation);

	TArray<FString> parsedData;
	const TCHAR* Delims[] = { TEXT(","), TEXT("\n") };
	rawData.ParseIntoArray(&parsedData, Delims, 2);

	if (selector >= parsedData.Num())
		return "Out of range";
	else
		return parsedData[selector];
}




