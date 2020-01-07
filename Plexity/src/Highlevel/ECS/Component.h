#pragma once


namespace Plexity
{

	enum ComponentTypes
	{
		Transform = 0,
	};
	
	class Component
	{
	public:
		virtual ~Component() = default;

		virtual void OnAwake();
		virtual void OnUpdate();
		virtual void OnDestroy();
		
	private:
		
	};
	
}