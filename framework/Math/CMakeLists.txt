add_library(MathCalcLib SHARED StatisticsCalculator.cpp)

target_include_directories(MathCalcLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})