solution "gmsv_example"

	language "C++"
	location ( os.get() .."-".. _ACTION )
	flags { "Symbols", "NoEditAndContinue", "NoPCH", "StaticRuntime", "EnableSSE" }
	targetdir ( "lib/" .. os.get() .. "/" )
	includedirs { "../include/" }

	if os.get() == "macosx" then
		platform { "universal32" }
	else
		platform { "x32" }
	end 
	
	configurations
	{ 
		"Release"
	}
	
	configuration "Release"
		defines { "NDEBUG" }
		flags{ "Optimize", "FloatFast" }
	
	project "gmsv_example"
		defines { "GMMODULE" }
		files { "src/**.*", "../include/**.*" }
		kind "SharedLib"
		