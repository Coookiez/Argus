#pragma once

#ifdef AS_PLATFORM_WINDOWS

extern Argus::Application* Argus::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Argus::CreateApplication();
	app->Run();
	delete app;
}


#endif // 
