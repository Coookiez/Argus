#include "aspch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Argus
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_windowHandle(windowHandle)
	{
		AS_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		AS_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AS_CORE_ASSERT(status, "Failed to initialize Glad!");

		AS_CORE_INFO("OpenGL Info:");
		AS_CORE_INFO("  Vendor : {0}", glGetString(GL_VENDOR));
		AS_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		AS_CORE_INFO("  Version: {0}",  glGetString(GL_VERSION));

		AS_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Argus requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		AS_PROFILE_FUNCTION();

		glfwSwapBuffers(m_windowHandle);
	}
}