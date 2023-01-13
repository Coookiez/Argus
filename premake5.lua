include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Argus"
	architecture "x86_64"
	startproject "Argus-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Argus/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Argus/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Argus/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Argus/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Argus/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Argus/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Argus/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Argus/vendor/ImGuizmo"

group "Dependencies"
	include "vendor/premake"
	include "Argus/vendor/GLFW"
	include "Argus/vendor/Glad"
	include "Argus/vendor/imgui"
	include "Argus/vendor/yaml-cpp"
group ""

include "Argus"
include "Sandbox"
include "Argus-Editor"