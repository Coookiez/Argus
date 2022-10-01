#pragma once

#include "Argus/Renderer/RenderCommand.h"
#include "Argus/Renderer/OrthographicCamera.h"
#include "Argus/Renderer/Shader.h"

namespace Argus
{
	class Renderer
	{
	public:
		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);


		inline RendererAPI::API static GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};
}