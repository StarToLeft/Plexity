workspace "Plexity"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Plexity/vendor/GLFW/include"
IncludeDir["Glad"] = "Plexity/vendor/Glad/include"
IncludeDir["ImGui"] = "Plexity/vendor/imgui"
IncludeDir["glm"] = "Plexity/vendor/glm"
IncludeDir["stb_image"] = "Plexity/vendor/stb_image"

include "Plexity/vendor/GLFW"
include "Plexity/vendor/Glad"
include "Plexity/vendor/imgui"

project "Plexity"
	location "Plexity"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("build/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("build/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pxpch.h"
	pchsource "Plexity/src/pxpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
	
	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PX_PLATFORM_WINDOWS",
			"PX_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "PX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PX_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PX_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("build/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("build/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Plexity/vendor/spdlog/include",
		"Plexity/src",
		"Plexity/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.Glad}",
	}

	links
	{
		"Plexity"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PX_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PX_DIST"
		runtime "Release"
		optimize "on"