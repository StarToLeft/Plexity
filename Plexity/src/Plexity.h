#pragma once

#include "Engine/Application/Application.h"
#include "Engine/Layer/Layer.h"
#include "Engine/Core/Logging/Log.h"

#include "Engine/Math/Physics/Timestep.h"

#include "Engine/Application/Input/Input.h"
#include "Engine/Application/Input/KeyCodes.h"
#include "Engine/Application/Input/MouseButtonCodes.h"
#include "Engine/Renderer/Camera/OrthographicCameraController.h"

// -- Intermediate UI --
#include "Engine/Layer/ImGui/ImGuiLayer.h"

// -- Renderer --
#include "Engine/Renderer/Renderer.h"
#include "Engine/Renderer/2D/Renderer2D.h"
#include "Engine/Renderer/RenderCommand.h"

#include "Engine/Renderer/Buffer.h"
#include "Engine/Renderer/Shader.h"
#include "Engine/Renderer/VertexArray.h"
#include "Engine/Renderer/Texture/Texture.h"

#include "Engine/Renderer/Camera/OrthographicCamera.h"

// -- Entry point --
#include "Engine/Core/EntryPoint.h"

// -- High level --
#include "Highlevel/ECS/Object.h"