workspace "Artificial Intelligence"
    architecture "x64"
    
    configurations 
    {
        "Debug",
        "Release"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"

project "Neuron"
    location "Neuron"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir ("bin/intermediates/" .. outputdir)

    staticruntime "on"

    files
    {
        "**.h",
        "**.cpp"
    }
    
    filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"


	filter "configurations:Debug"
		defines "BM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BM_RELEASE"
		optimize "On"
