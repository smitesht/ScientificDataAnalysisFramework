cmake_minimum_required(VERSION 3.28)
project(SciFlow VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.12.0
    )

FetchContent_MakeAvailable(nlohmann_json)

add_subdirectory(config)
add_subdirectory(framework)
add_subdirectory(plugins)
add_subdirectory(app)