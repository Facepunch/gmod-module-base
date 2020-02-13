set(SOURCES
	HelloWorld.cpp)

add_library(HelloWorld SHARED ${SOURCES})
target_link_libraries(HelloWorld gmod-module-base)

set_gmod_suffix_prefix(HelloWorld)