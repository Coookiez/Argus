include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

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

group "Dependencies"
	include "vendor/premake"
	include "Argus/vendor/GLFW"
	include "Argus/vendor/Glad"
	include "Argus/vendor/imgui"
	include "Argus/vendor/yaml-cpp"
group ""

group "Core"
	include "Argus"
group ""

group "Tools"
	include "Argus-Editor"
group ""

group "Misc"
	include "Sandbox"
group ""