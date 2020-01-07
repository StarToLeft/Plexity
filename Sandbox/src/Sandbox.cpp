#include <Plexity.h>

#include <ImGui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Glad/glad.h>

class Renderer2D final : public Plexity::Layer
{
public:
	Renderer2D()
		: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
	{
	}

	void OnAwake() override
	{
		PX_PROFILE_FUNCTION();

		m_CheckerboardTexture = Plexity::Texture2D::Create("assets/textures/Checkerboard.png");

		player = new Plexity::Object("Player");
	}

	void OnDetach() override
	{
		PX_PROFILE_FUNCTION();
	}

	void OnUpdate(Plexity::Timestep ts) override
	{
		// Update
		m_CameraController.OnUpdate(ts);

		// Render
		{
			PX_PROFILE_SCOPE("Renderer Prep");
			Plexity::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			Plexity::RenderCommand::Clear();
		}

		player->OnUpdate(ts);

		frameCount++;
		dt += ts;
		if (dt > 1.0f / updateRate)
		{
			fps = frameCount / dt;
			frameCount = 0;
			dt -= 1.0f / updateRate;
		}

		PX_INFO("Fps: {0}", fps);
		
		// Draw
		{
			PX_PROFILE_SCOPE("Renderer Draw");

			Plexity::Renderer2D::BeginScene(m_CameraController.GetCamera());
			
			Plexity::Renderer2D::DrawRect(posRed, { 0.8f, 0.8f }, m_SquareColor, 
				Plexity::Renderer2D::DrawOptions{ rotRed, 0.f });

			Plexity::Renderer2D::DrawRect({ 0.0f, 0.0f, -0.1f }, { 100.0f, 100.0f },
				m_CheckerboardTexture, Plexity::Renderer2D::DrawOptions{ 0.f, 60.f });
			
			Plexity::Renderer2D::EndScene();
		}
	}

	void OnGuiRender() override
	{
		PX_PROFILE_FUNCTION();
		ImGui::Begin("Settings");
		ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::DragFloat2("Pos", glm::value_ptr(posRed), 0.1f);
		ImGui::DragFloat("Rotation", &rotRed, 0.1f);
		ImGui::End();
	}

	void OnEvent(Plexity::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}

private:
	Plexity::ShaderLibrary m_ShaderLibrary;
	Plexity::Ref<Plexity::Shader> m_FlatColorShader;

	Plexity::Ref<Plexity::VertexArray> m_SquareVA;

	Plexity::OrthographicCameraController m_CameraController;

	Plexity::Ref<Plexity::Texture2D> m_CheckerboardTexture;

	Plexity::Object* player;

	glm::vec2 posRed = { 0.0f, 0.0f };
	float rotRed = 0.0f;
	
	glm::vec4 m_SquareColor = { 1.f, 1.f, 1.f, 1.f };




	float frameCount = 0;
	float dt = 0.0;
	float fps = 0.0;
	float updateRate = 4.0;  // 4 updates per sec.
};

class Sandbox2D final : public Plexity::Application
{
public:
	Sandbox2D()
	{
		PushLayer(new Renderer2D());
	}

	virtual ~Sandbox2D() = default;
};

Plexity::Application* Plexity::CreateApplication()
{
	return new Sandbox2D();
}
