#pragma once
#include "Engine/Renderer/RendererAPI.h"

namespace Plexity
{

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;

		virtual void SetViewport(int x, int y, uint32_t width, uint32_t height) override;
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;

		virtual char* GetGraphicsDriverVersion() override;
		virtual char* GetGraphicsRenderer() override;
	};
	
}
