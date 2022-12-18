#pragma once

#include "Argus/Core/Base.h"
#include "Argus/Core/Window.h"
#include "Argus/Core/LayerStack.h"
#include "Argus/Events/Event.h"
#include "Argus/Events/ApplicationEvent.h"

#include "Argus/Core/Timestep.h"

#include "Argus/ImGui/ImGuiLayer.h"

namespace Argus {

	class Application
	{
	public:
		Application(const std::string& name = "Argus App");
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		static Application* s_Instance;
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}