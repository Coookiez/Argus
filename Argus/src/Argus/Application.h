#pragma once

#include "Core.h"

#include "Argus/Window.h"
#include "Argus/LayerStack.h"
#include "Argus/Events/Event.h"
#include "Argus/Events/ApplicationEvent.h"

#include "Argus/ImGui/ImGuiLayer.h"

namespace Argus {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		static Application* s_Instance;
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

	};

	// To be defined in CLIENT
	Application* CreateApplication();

}