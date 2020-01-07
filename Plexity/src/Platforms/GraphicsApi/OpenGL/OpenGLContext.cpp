#include "pxpch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Plexity
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{
	}

	void OpenGLContext::Init()
	{
		PX_PROFILE_FUNCTION();
		
		glfwMakeContextCurrent(m_WindowHandle);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PX_CORE_ASSERT(status, "Failed to initialize Glad.");

		PX_CORE_INFO("OpenGL Renderer: {0} - {1}", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
		PX_CORE_INFO("    Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		PX_PROFILE_FUNCTION();
		
		glfwSwapBuffers(m_WindowHandle);
	}
}
