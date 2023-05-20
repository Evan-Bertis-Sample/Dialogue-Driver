file(GLOB INTERNAL_TEST_SOURCES "internal/*.cpp")
# file(GLOB DLL_INTERFACE_TEST_SOURCES "dll_interface/*.cpp")

add_executable(internal_tests ${INTERNAL_TEST_SOURCES})
# add_executable(dll_interface_tests ${DLL_INTERFACE_TEST_SOURCES})

target_include_directories(internal_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
# target_include_directories(dll_interface_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(internal_tests gtest gtest_main dialogue_driver_obj)
# target_link_libraries(dll_interface_tests gtest gtest_main dialogue_driver)

add_dependencies(internal_tests dialogue_driver_obj)
# add_dependencies(dll_interface_tests dialogue_driver)

add_test(InternalTests internal_tests)
# add_test(DLLInterfaceTests dll_interface_tests)

