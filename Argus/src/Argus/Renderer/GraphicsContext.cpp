#include "aspch.h"
#include "Argus/Renderer/GraphicsContext.h"

#include "Argus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Argus {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    AS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		AS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}