add_executable(${PROJECT_NAME} app.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE PluginManagerLib StatisticsPluginLib)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")