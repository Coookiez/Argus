#include "aspch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Argus
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}