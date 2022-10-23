#include "aspch.h"
#include "Argus/Renderer/Texture.h"

#include "Argus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Argus
{
	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: AS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return CreateRef<OpenGLTexture2D>(width, height);
		}

		AS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<Texture2D> Argus::Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: AS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return CreateRef<OpenGLTexture2D>(path);
		}

		AS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
