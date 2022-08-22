#pragma once

#include "Core.h"

#include "Argus/LayerStack.h"
#include "Argus/Window.h"
#include "Argus/Events/ApplicationEvent.h"
#include "Events/Event.h"


namespace Argus {

	class ARGUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();


}