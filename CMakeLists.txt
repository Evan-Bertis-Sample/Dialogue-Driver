# cmake_minimum_required(VERSION 3.10)
# project(Dialogue-Driver)

# add_subdirectory(libs)

# include_directories(include)

# # add_subdirectory(src)

# add_library(dialogue_driver SHARED src/driver.cpp)

# add_subdirectory(tests)

cmake_minimum_required(VERSION 3.15)
project(Dialogue-Driver)

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
add_subdirectory(tests)
