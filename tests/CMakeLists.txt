file(GLOB FACT_SYSTEM_TEST_SOURCES "fact_system/*.cpp")
file(GLOB NODE_TEST_SOURCES "node_system/*.cpp")
# file(GLOB DLL_INTERFACE_TEST_SOURCES "dll_interface/*.cpp")

add_executable(fact_system_tests ${FACT_SYSTEM_TEST_SOURCES})
add_executable(node_tests ${NODE_TEST_SOURCES})
# add_executable(dll_interface_tests ${DLL_INTERFACE_TEST_SOURCES})

target_include_directories(fact_system_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(node_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
# target_include_directories(dll_interface_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(fact_system_tests gtest gtest_main dialogue_driver_obj)
target_link_libraries(node_tests gtest gtest_main dialogue_driver_obj)
# target_link_libraries(dll_interface_tests gtest gtest_main dialogue_driver)

add_dependencies(fact_system_tests dialogue_driver_obj)
add_dependencies(node_tests dialogue_driver_obj)
# add_dependencies(dll_interface_tests dialogue_driver)

add_test(FactSystemTests fact_system_tests)
add_test(NodeSystemTests node_tests)
# add_test(DLLInterfaceTests dll_interface_tests)

