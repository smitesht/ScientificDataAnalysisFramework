cmake_minimum_required(VERSION 3.28)
project(SciFlow VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(framework)
add_subdirectory(plugins)
add_subdirectory(app)