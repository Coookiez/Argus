#include "aspch.h"
#include "Argus/Renderer/RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Argus
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}