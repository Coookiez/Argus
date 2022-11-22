#pragma once

#include "Argus/Core/Layer.h"

#include "Argus/Events/ApplicationEvent.h"
#include "Argus/Events/KeyEvent.h"
#include "Argus/Events/MouseEvent.h"

namespace Argus
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

	private:
		float m_Time = 0.f;
	};
}