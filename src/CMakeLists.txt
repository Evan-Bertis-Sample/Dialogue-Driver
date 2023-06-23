if (BUILD_DLL)
    file(GLOB SOURCES "*.cpp")

    add_library(dialogue_driver_obj OBJECT ${SOURCES})
    add_library(dialogue_driver SHARED $<TARGET_OBJECTS:dialogue_driver_obj>)

    target_include_directories(dialogue_driver_obj PRIVATE ${PROJECT_SOURCE_DIR}/include)
    target_include_directories(dialogue_driver PRIVATE ${PROJECT_SOURCE_DIR}/include)

    set_target_properties(dialogue_driver PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/lib
        ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/lib
    )
endif()
