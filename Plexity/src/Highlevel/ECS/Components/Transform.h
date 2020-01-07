#pragma once

#include "Highlevel/ECS/Component.h"

#include <glm/glm.hpp>

namespace Plexity
{

	class Transform : Component
	{
	public:
		virtual void OnAwake() override;
		virtual void OnUpdate() override;
		virtual void OnDestroy() override;
		
		glm::vec3 position;
		glm::vec3 rotation;
		
		glm::vec2 size;
	};
	
}

