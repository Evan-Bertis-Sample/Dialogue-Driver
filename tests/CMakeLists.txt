file(GLOB FACT_SYSTEM_TEST_SOURCES "fact_system/*.cpp")
file(GLOB NODE_TEST_SOURCES "node_system/*.cpp")
# file(GLOB DLL_INTERFACE_TEST_SOURCES "dll_interface/*.cpp")
file(GLOB END_TO_END_SOURCES "end_to_end/*.cpp")

add_executable(fact_system_tests ${FACT_SYSTEM_TEST_SOURCES})
add_executable(node_tests ${NODE_TEST_SOURCES})
# add_executable(dll_interface_tests ${DLL_INTERFACE_TEST_SOURCES})
add_executable(end_to_end_tests ${END_TO_END_SOURCES})

target_include_directories(fact_system_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(node_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
# target_include_directories(dll_interface_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(end_to_end_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(fact_system_tests gtest gtest_main dialogue_driver_obj)
target_link_libraries(node_tests gtest gtest_main dialogue_driver_obj)
# target_link_libraries(dll_interface_tests gtest gtest_main dialogue_driver)
target_link_libraries(end_to_end_tests dialogue_driver_obj)

add_dependencies(fact_system_tests dialogue_driver_obj)
add_dependencies(node_tests dialogue_driver_obj)
# add_dependencies(dll_interface_tests dialogue_driver)
add_dependencies(end_to_end_tests dialogue_driver_obj)

add_test(FactSystemTests fact_system_tests)
add_test(NodeSystemTests node_tests)
# add_test(DLLInterfaceTests dll_interface_tests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/tests)
set_target_properties(end_to_end_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})