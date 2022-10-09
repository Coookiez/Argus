#include "aspch.h"
#include "Argus/Renderer/Texture.h"

#include "Argus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Argus
{
	Ref<Texture2D> Argus::Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: AS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture2D>(path);
		}

		AS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
