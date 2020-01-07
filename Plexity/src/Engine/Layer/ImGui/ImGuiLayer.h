#pragma once

#include "Engine/Layer/Layer.h"

#include "Engine/Application/Events/ApplicationEvent.h"
#include "Engine/Application/Events/KeyEvent.h"
#include "Engine/Application/Events/MouseEvent.h"

namespace Plexity {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAwake() override;
		virtual void OnDetach() override;
		virtual void OnGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}