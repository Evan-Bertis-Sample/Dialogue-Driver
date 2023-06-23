cmake_minimum_required(VERSION 3.15)
project(Dialogue-Driver)

option(BUILD_TEST "Build Tests" OFF)
option(BUILD_DLL "Build the DLL" OFF)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()


# Enable testing functionality
enable_testing()

# Google Test
add_subdirectory(libs/googletest)

# Include sub-projects.
add_subdirectory(src)

if(BUILD_TEST AND EXISTS tests)
    add_subdirectory(tests)
endif()
