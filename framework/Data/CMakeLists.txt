add_library(DataLib SHARED NumberFileReader.cpp)

target_include_directories(DataLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})