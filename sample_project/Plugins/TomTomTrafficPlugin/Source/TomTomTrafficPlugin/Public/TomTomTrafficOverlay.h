#pragma once

#include "ArcGISMapsSDK/Public/ArcGISMapsSDK.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TomTomTrafficOverlay.generated.h"

UCLASS()
class TOMTOMTRAFFICPLUGIN_API ATomTomTrafficOverlay : public AActor
{
	GENERATED_BODY()

public:
	void DisplayTrafficData(const FString& TrafficData);

private:
	// Add any private member variables or helper functions here
};
