#pragma once

#include "Component.h"
#include "Engine/Math/Physics/Timestep.h"

namespace Plexity
{
	class Object
	{
	public:
		Object(std::string name);
		~Object();

		void OnUpdate(Plexity::Timestep ts);

		void AddComponent(const std::string name, Component component) { m_Components[name] = std::move(component); }
		std::unordered_map<std::string, Component> GetComponents() const { return m_Components; }
		
	public:
		std::string m_Name;
		
		std::unordered_map<std::string, Component> m_Components;
	};
	
}
