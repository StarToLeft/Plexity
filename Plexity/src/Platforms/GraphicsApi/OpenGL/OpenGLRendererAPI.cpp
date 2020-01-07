#include "pxpch.h"
#include "OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace Plexity
{
	void OpenGLRendererAPI::Init()
	{
		PX_PROFILE_FUNCTION();
		
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
	}

	void OpenGLRendererAPI::SetViewport(int x, int y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::DrawIndexed(const Ref<VertexArray>& vertexArray)
	{
		glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	char* OpenGLRendererAPI::GetGraphicsDriverVersion()
	{
		return (char*)glGetString(GL_VERSION);
	}

	char* OpenGLRendererAPI::GetGraphicsRenderer()
	{
		return (char*)glGetString(GL_RENDERER);
	}
}
