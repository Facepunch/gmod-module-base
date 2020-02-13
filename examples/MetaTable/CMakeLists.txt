set(SOURCES
	MetaTable.cpp)

add_library(MetaTable SHARED ${SOURCES})
target_link_libraries(MetaTable gmod-module-base)

set_gmod_suffix_prefix(MetaTable)