#pragma once

#ifdef PX_PLATFORM_WINDOWS

extern Plexity::Application* Plexity::CreateApplication();

int main(int argc, char** argv)
{
	Plexity::Log::Init();

	PX_PROFILE_BEGIN_SESSION("Startup", "PlexityProfile-Startup.json");
	auto app = Plexity::CreateApplication();
	PX_PROFILE_END_SESSION();

	PX_PROFILE_BEGIN_SESSION("Runtime", "PlexityProfile-Runtime.json");
	app->Run();
	PX_PROFILE_END_SESSION();

	PX_PROFILE_BEGIN_SESSION("Startup", "PlexityProfile-Shutdown.json");
	delete app;
	PX_PROFILE_END_SESSION();
}

#endif
