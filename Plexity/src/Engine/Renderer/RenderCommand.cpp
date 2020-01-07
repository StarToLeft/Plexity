#include "pxpch.h"
#include "RenderCommand.h"

#include "Platforms/GraphicsApi/OpenGL/OpenGLRendererAPI.h"

namespace Plexity
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}