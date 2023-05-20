# # find all .cpp files in the 'src' directory
# file(GLOB SOURCES "*.cpp")

# # Add the library
# add_library(Dialogue-Driver SHARED ${SOURCES})

file(GLOB SOURCES "*.cpp")

add_library(dialogue_driver_obj OBJECT ${SOURCES})
add_library(dialogue_driver SHARED $<TARGET_OBJECTS:dialogue_driver_obj>)

target_include_directories(dialogue_driver_obj PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(dialogue_driver PRIVATE ${PROJECT_SOURCE_DIR}/include)

set_target_properties(dialogue_driver PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src
)


