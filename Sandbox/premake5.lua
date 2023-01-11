project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Argus/vendor/spdlog/include",
		"%{wks.location}/Argus/src",
		"%{wks.location}/Argus/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Argus"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "AS_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "AS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "AS_DIST"
		runtime "Release"
		optimize "on"