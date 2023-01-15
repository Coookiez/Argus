#pragma once

#include "Argus/Core/Base.h"
#include "Argus/Core/Log.h"
#include "Argus/Scene/Scene.h"
#include "Argus/Scene/Entity.h"

namespace Argus
{
	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);
		void OnImGuiRender();

		Entity GetSelectedEntity() const { return m_SelectionContext; }
		void SetSelectedEntity(Entity entity);

	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);

		
		Ref<Scene> m_Context;
		Entity m_SelectionContext;

	};
}