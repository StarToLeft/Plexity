#include "pxpch.h"
#include "Renderer2D.h"

#include "Engine/Renderer/VertexArray.h"
#include "Engine/Renderer/Shader.h"
#include "Engine/Renderer/RenderCommand.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Plexity {

	struct Renderer2DStorage
	{
		Ref<VertexArray> m_QuadVertexArray;
		Ref<Shader> m_TextureShader;
		Ref<Texture2D> m_WhiteTexture;

		std::unordered_map<std::string, Object*> objects;
	};

	static Renderer2DStorage* s_Data;

	void Renderer2D::Init()
	{
		PX_PROFILE_FUNCTION();
		
		s_Data = new Renderer2DStorage();
		s_Data->m_QuadVertexArray = VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Ref<VertexBuffer> squareVB;
		squareVB.reset(VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ ShaderDataType::Float3, "a_Position" },
			{ ShaderDataType::Float2, "a_TexCoord" }
			});
		s_Data->m_QuadVertexArray->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		Ref<IndexBuffer> squareIB;
		squareIB.reset(IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		s_Data->m_QuadVertexArray->SetIndexBuffer(squareIB);

		s_Data->m_WhiteTexture = Texture2D::Create(1, 1);
		uint32_t whiteTextureData = 0xffffffff;
		s_Data->m_WhiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));
		
		s_Data->m_TextureShader = Shader::Create("assets/shaders/Texture.glsl");
		s_Data->m_TextureShader->Bind();
		s_Data->m_TextureShader->SetInt("u_Texture", 0);
	}

	void Renderer2D::Shutdown()
	{
		PX_PROFILE_FUNCTION();
		
		delete s_Data;
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		PX_PROFILE_FUNCTION();
		
		s_Data->m_TextureShader->Bind();
		s_Data->m_TextureShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());
	}

	void Renderer2D::EndScene()
	{
		PX_PROFILE_FUNCTION();
	}

	void Renderer2D::AddObject(std::string name, Object* object)
	{
		s_Data->objects[std::move(name)] = object;
	}

	void Renderer2D::RemoveObject(std::string name)
	{
		s_Data->objects.erase(name);
	}

	void Renderer2D::DrawRect(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawRect({ position.x, position.y, 0.0f }, size, color, DrawOptions{ 0.f, 1.f });
	}

	void Renderer2D::DrawRect(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawRect(position, size, color, DrawOptions{ 0.f, 1.f });
	}

	void Renderer2D::DrawRect(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture)
	{
		DrawRect({ position.x, position.y, 0.0f }, size, texture, DrawOptions{ 0.f, 1.f });
	}

	void Renderer2D::DrawRect(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture)
	{
		DrawRect(position, size, texture, DrawOptions{ 0.f, 1.f });
	}

	void Renderer2D::DrawRect(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color, DrawOptions drawOptions)
	{
		DrawRect({ position.x, position.y, 0.0f }, size, color, drawOptions);
	}

	void Renderer2D::DrawRect(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color, DrawOptions drawOptions)
	{
		{
			PX_PROFILE_FUNCTION();

			s_Data->m_TextureShader->SetFloat4("u_Color", color);
			s_Data->m_TextureShader->SetFloat("u_Tiling", 1.f);
			s_Data->m_WhiteTexture->Bind();
		}
			
		{
			PX_PROFILE_FUNCTION();
			
			const glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * 
										glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f }) *
										glm::rotate(glm::mat4(1.f), glm::radians(drawOptions.m_Rotation), glm::vec3(0, 0, 1));
			s_Data->m_TextureShader->SetMat4("u_Transform", transform);
		}

		{
			PX_PROFILE_FUNCTION();
			
			s_Data->m_QuadVertexArray->Bind();
			RenderCommand::DrawIndexed(s_Data->m_QuadVertexArray);
		}
	}

	void Renderer2D::DrawRect(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, DrawOptions drawOptions)
	{
		DrawRect({ position.x, position.y, 0.0f }, size, texture, drawOptions);
	}

	void Renderer2D::DrawRect(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, DrawOptions drawOptions)
	{
		{
			{
				PX_PROFILE_FUNCTION();
				
				s_Data->m_TextureShader->SetFloat4("u_Color", glm::vec4(1.0f));
				s_Data->m_TextureShader->SetFloat("u_Tiling", drawOptions.m_TilingFactor);
				texture->Bind();
			}
			
			{
				PX_PROFILE_FUNCTION();
				
				const glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * 
											glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f }) *
											glm::rotate(glm::mat4(1.f), glm::radians(drawOptions.m_Rotation), glm::vec3(0, 0, 1));
				s_Data->m_TextureShader->SetMat4("u_Transform", transform);
			}

			{
				PX_PROFILE_FUNCTION();
				
				s_Data->m_QuadVertexArray->Bind();
				RenderCommand::DrawIndexed(s_Data->m_QuadVertexArray);
			}
		}
	}
}
