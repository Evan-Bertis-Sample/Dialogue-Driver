# find all .cpp files in the 'src' directory
file(GLOB SOURCES "*.cpp")

# Add the library
add_library(Dialogue-Driver SHARED ${SOURCES})