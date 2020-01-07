#pragma once

namespace Plexity {

	class GraphicsContext
	{
	public:
		virtual void Init() {};
		virtual void SwapBuffers() {};

		static Scope<GraphicsContext> Create(void* window);
	};

}