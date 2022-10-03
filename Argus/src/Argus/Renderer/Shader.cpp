#include "aspch.h"
#include "Argus/Renderer/Shader.h"

#include "Argus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Argus
{
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: AS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		AS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}