add_library(DataLib STATIC CsvFileReader.cpp JsonFileReader.cpp FileReaderFactory.cpp)

target_include_directories(DataLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(DataLib PUBLIC SciFlowInterfacesLib SciFlowExceptionLib)