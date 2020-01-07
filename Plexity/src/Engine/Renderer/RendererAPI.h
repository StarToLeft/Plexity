#pragma once

#include <glm/glm.hpp>

#include "VertexArray.h"

namespace Plexity {

	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0, OpenGL = 1
		};
	public:
		virtual void Init() {}
		
		virtual void SetViewport(int x, int y, uint32_t width, uint32_t height) {}
		virtual void SetClearColor(const glm::vec4& color) {}
		
		virtual void Clear() {}

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) {}

		virtual char* GetGraphicsDriverVersion() { return {}; }
		virtual char* GetGraphicsRenderer() { return {}; }

		inline static API GetAPI() { return s_API; }
	private:
		static API s_API;
	};

}