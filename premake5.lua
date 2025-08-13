workspace "Magnum"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"Magnum/vendor/spdlog/include",
		"Magnum/src"
	}

	links
	{
		"Magnum"
	}

	buildoptions { "/utf-8" } 

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MAGNUM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MAGNUM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MAGNUM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MAGNUM_DIST"
		optimize "On"

project "Magnum"
	location "Magnum"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	 buildoptions { "/utf-8" } 

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MAGNUM_PLATFORM_WINDOWS",
			"MAGNUM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MAGNUM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MAGNUM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MAGNUM_DIST"
		optimize "On"

