add_library(MathCalcLib STATIC StatisticsCalculator.cpp)

set_target_properties(MathCalcLib PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(MathCalcLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})