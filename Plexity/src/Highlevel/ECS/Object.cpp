#include "pxpch.h"

#include "Object.h"

#include "Engine/Renderer/Renderer.h"

Plexity::Object::Object(const std::string name)
{
	PX_PROFILE_FUNCTION();
	Renderer::AddObject(name, this);

	m_Name = name;
}

Plexity::Object::~Object()
{
	PX_PROFILE_FUNCTION();
	Renderer::RemoveObject(m_Name);
}

void Plexity::Object::OnUpdate(Plexity::Timestep ts)
{
	PX_PROFILE_FUNCTION();
}
