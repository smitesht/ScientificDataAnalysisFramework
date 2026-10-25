add_library(PluginManagerLib STATIC PluginManager.cpp SharedLibrary.cpp)

target_include_directories(PluginManagerLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})