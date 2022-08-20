workspace "Argus"
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
IncludeDir["GLFW"] = "Argus/vendor/GLFW/include"

include "Argus/vendor/GLFW"

project "Argus"
	location "Argus"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "aspch.h"
	pchsource "Argus/src/aspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AS_PLATFORM_WINDOWS",
			"AS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.abspath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AS_DEBUG"
		buildoptions"/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "AS_RELEASE"
		buildoptions"/MD"
		symbols "On"

	filter "configurations:Dist"
		defines "AS_DIST"
		buildoptions"/MD"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Argus/vendor/spdlog/include",
		"Argus/src"
	}

	links
	{
		"Argus"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AS_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "AS_DIST"
		symbols "On"
		optimize "On"