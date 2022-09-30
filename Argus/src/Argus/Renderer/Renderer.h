#pragma once

#include "Argus/Renderer/RenderCommand.h"

namespace Argus
{
	class Renderer
	{
	public:
		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

		inline RendererAPI::API static GetAPI() { return RendererAPI::GetAPI(); }
	};
}