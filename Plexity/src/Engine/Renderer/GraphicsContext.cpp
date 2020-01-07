#include "pxpch.h"
#include "Engine/Renderer/GraphicsContext.h"

#include "Engine/Renderer/Renderer.h"
#include "Platforms/GraphicsApi/OpenGL/OpenGLContext.h"

namespace Plexity {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    PX_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		PX_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}