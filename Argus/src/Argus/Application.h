#pragma once

#include "Core.h"

namespace Argus {

	class ARGUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();


}