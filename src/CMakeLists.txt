file(GLOB SOURCES "*.cpp")

# Build a DLL.
add_library(myproject SHARED ${SOURCES})

# Link against Google Test.
target_link_libraries(myproject gtest gtest_main)