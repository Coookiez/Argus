#pragma once

#include "entt.hpp"

#include "Argus/Core/Timestep.h"
#include "Argus/Renderer/EditorCamera.h"

namespace Argus
{
	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());
		Entity GetPrimaryCameraEntity();
		void DestroyEntity(Entity entity);

		// TEMP
		entt::registry& Reg() { return m_Registry; }

		void OnUpdateRuntime(Timestep ts);
		void OnUpdateEditor(Timestep ts, EditorCamera& camera);
		void OnViewportResize(uint32_t width, uint32_t height);

	private:
		template<typename T>
		void OnComponentAdded(Entity entity, T& component);

		entt::registry m_Registry;
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

		friend class Entity;
		friend class SceneSerializer;
		friend class SceneHierarchyPanel;
	};
}