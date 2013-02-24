gmod-module-base
================

Technically everything you need is in include.

Example contains an example project. Running BuildProjects.bat requires premake4 (http://industriousone.com/premake).

The generated dlls should be placed in

garrysmod/lua/bin/

They should also be named approriately.

gmsv_example_win32.dll  <- require( 'example' ) serverside on windows
gmsv_example_linux.dll  <- require( 'example' ) serverside on linux
gmsv_example_osx.dll	<- require( 'example' ) serverside on osx

gmcl_nutsack_win32.dll	<- require( 'nutsack' ) clientside on windows
gmcl_example_osx.dll	<- require( 'example' ) clientside on osx
