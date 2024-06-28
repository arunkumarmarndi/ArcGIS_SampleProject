#include "TomTomTrafficAPI.h"

void UTomTomTrafficAPI::FetchRouteAnalysis()
{
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UTomTomTrafficAPI::OnRouteAnalysisReceived);
	Request->SetURL("https://api.tomtom.com/traffic/trafficstats/routeanalysis/1?key=AohWLAaQhynVHXELpJgVmeQTWS56MVKL");
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString("{ \"jobName\": \"Test job\", \"routes\": [{\"name\": \"Route\", \"start\": {\"latitude\": 52.41072, \"longitude\": "
								"4.84239}, \"end\": {\"latitude\": 52.41782, \"longitude\": 4.88536}}]}");
	Request->ProcessRequest();
}

void UTomTomTrafficAPI::OnRouteAnalysisReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		FString ResponseString = Response->GetContentAsString();
		UE_LOG(LogTemp, Warning, TEXT("Route Analysis Data: %s"), *ResponseString);
		// Process and display the data using ArcGIS
	}
}
