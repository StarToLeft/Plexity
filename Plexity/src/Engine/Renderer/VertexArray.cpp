#include "pxpch.h"

#include "VertexArray.h"

#include "Engine/Renderer/Renderer.h"
#include "Platforms/GraphicsApi/OpenGL/OpenGLVertexArray.h"

namespace Plexity
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    PX_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_shared<OpenGLVertexArray>();
		}

		PX_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	
}
