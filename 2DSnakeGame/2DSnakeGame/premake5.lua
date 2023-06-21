project "2DSnakeGame"
    kind "ConsoleApp"
    language "C++"

    targetdir("../build/bin/" .. outputdir .. "/%{prj.name}")
    objdir("../build/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "header/**.hpp", 
        "header/**.h", 
        "interfaces/**.h",
        "manager/**.h",
        "manager/**.cpp",
        "src/**.cpp",
        "**.lua" 
    }

    includedirs { "../External/SFML/include" }
    
    libdirs { "../External/SFML/lib" }

    links { "opengl32.lib", "freetype.lib", "winmm.lib", "gdi32.lib", "openal32.lib", "flac.lib", "vorbisenc.lib", "vorbisfile.lib", "vorbis.lib", "ogg.lib", "ws2_32.lib" }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines { "GAME_PLATFORM_WINDOWS", "SFML_STATIC" }


    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

        links { "sfml-audio-s-d.lib", "sfml-graphics-s-d.lib", "sfml-network-s-d.lib", "sfml-system-s-d.lib", "sfml-window-s-d.lib" }

    filter { "configurations:Release" }
        runtime "Release"
        optimize "on"
        
        links { "sfml-audio-s.lib", "sfml-graphics-s.lib", "sfml-network-s.lib", "sfml-system-s.lib", "sfml-window-s.lib" }
