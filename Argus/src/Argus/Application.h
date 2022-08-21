#pragma once

#include "Core.h"

#include "Argus/Events/ApplicationEvent.h"
#include "Argus/Window.h"
#include "Events/Event.h"


namespace Argus {

	class ARGUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();


}