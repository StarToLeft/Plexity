#pragma once

#include "Engine/Renderer/Camera/OrthographicCamera.h"
#include "Engine/Renderer/Texture/Texture.h"
#include "Highlevel/ECS/Object.h"

namespace Plexity {

	class Renderer2D
	{
	public:
		struct DrawOptions
		{
			float m_Rotation = 0.f;
			float m_TilingFactor = 1.f;
		};
		
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

		static void AddObject(std::string name, Object* object);
		static void RemoveObject(std::string name);

		// Primitives
		static void DrawRect(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawRect(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawRect(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture);
		static void DrawRect(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture);
		static void DrawRect(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color, DrawOptions drawOptions);
		static void DrawRect(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color, DrawOptions drawOptions);
		static void DrawRect(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, DrawOptions drawOptions);
		static void DrawRect(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, DrawOptions drawOptions);
	};

}
