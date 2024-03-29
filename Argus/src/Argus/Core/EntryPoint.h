#pragma once

#include "Argus/Core/Base.h"
#include "Argus/Core/Application.h"

#ifdef AS_PLATFORM_WINDOWS

extern Argus::Application* Argus::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Argus::Log::Init();

	AS_PROFILE_BEGIN_SESSION("Startup", "ArgusProfile-Startup.json");
	auto app = Argus::CreateApplication({ argc, argv });
	AS_PROFILE_END_SESSION();
	
	AS_PROFILE_BEGIN_SESSION("Startup", "ArgusProfile-Runtime.json");
	app->Run();
	AS_PROFILE_END_SESSION();
	
	AS_PROFILE_BEGIN_SESSION("Shutdown", "ArgusProfile-Shutdown.json");
	delete app;
	AS_PROFILE_END_SESSION();

}
#endif // 