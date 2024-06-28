#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FTomTomTrafficPluginModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	class UTomTomTrafficAPI* TomTomTrafficAPI;
	class ATomTomTrafficOverlay* TomTomTrafficOverlay;
};
