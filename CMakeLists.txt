cmake_minimum_required(VERSION 3.10)
project(Dialogue-Driver)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs)

include_directories(include)

add_library(dialogue_driver SHARED src/driver.cpp)

add_subdirectory(tests)