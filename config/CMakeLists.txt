add_library(ConfigLib STATIC ConfigConstant.cpp ConfigManager.cpp)

target_include_directories(ConfigLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})