#pragma once

#include "Argus/Core/Core.h"
#include "Argus/Core/Timestep.h"
#include "Argus/Events/Event.h"

namespace Argus
{
	class ARGUS_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& e) {}

		const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}