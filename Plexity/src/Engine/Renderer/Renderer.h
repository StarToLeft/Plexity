#pragma once

#include "Engine/Renderer/RenderCommand.h"

#include "Engine/Renderer/Camera/OrthographicCamera.h"
#include "Engine/Renderer/Shader.h"

#include "Highlevel/ECS/Object.h"

namespace Plexity {

	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

		static void OnWindowResize(uint32_t width, uint32_t height);

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

		static void AddObject(std::string name, Object* object);
		static void RemoveObject(std::string name);
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static Scope<SceneData> s_SceneData;
	};
}