#pragma once

#include "RendererAPI.h"

namespace Plexity
{

	class RenderCommand
	{
	public:
		static void Init()
		{
			s_RendererAPI->Init();
		}
		
		static void SetClearColor(const glm::vec4& color)
		{
			s_RendererAPI->SetClearColor(color);
		}

		static void Clear()
		{
			s_RendererAPI->Clear();
		}

		static void SetViewport(int x, int y, uint32_t width, uint32_t height)
		{
			s_RendererAPI->SetViewport(x, y, width, height);
		}

		static void DrawIndexed(const Ref<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndexed(vertexArray);
		}
		
		static char* GetGraphicsDriverVersion()
		{
			return s_RendererAPI->GetGraphicsDriverVersion();
		}
		
		static char* GetGraphicsRenderer()
		{
			return s_RendererAPI->GetGraphicsRenderer();
		}
		
	private:
		static RendererAPI* s_RendererAPI;
	};

	
}