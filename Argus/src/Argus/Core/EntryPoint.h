#pragma once

#ifdef AS_PLATFORM_WINDOWS

extern Argus::Application* Argus::CreateApplication();

int main(int argc, char** argv)
{
	Argus::Log::Init();
	AS_CORE_ERROR("Initialized Log!");
	int a = 5;
	AS_INFO("Hello! var={0}", a);

	auto app = Argus::CreateApplication();
	app->Run();
	delete app;
}


#endif // 