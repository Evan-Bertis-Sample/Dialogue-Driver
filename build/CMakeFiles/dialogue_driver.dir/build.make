# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:/Documents/Code/Personal Projects/Dialogue-Driver"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:/Documents/Code/Personal Projects/Dialogue-Driver/build"

# Include any dependencies generated for this target.
include CMakeFiles/dialogue_driver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dialogue_driver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dialogue_driver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dialogue_driver.dir/flags.make

CMakeFiles/dialogue_driver.dir/src/driver.cpp.obj: CMakeFiles/dialogue_driver.dir/flags.make
CMakeFiles/dialogue_driver.dir/src/driver.cpp.obj: CMakeFiles/dialogue_driver.dir/includes_CXX.rsp
CMakeFiles/dialogue_driver.dir/src/driver.cpp.obj: D:/Documents/Code/Personal\ Projects/Dialogue-Driver/src/driver.cpp
CMakeFiles/dialogue_driver.dir/src/driver.cpp.obj: CMakeFiles/dialogue_driver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:/Documents/Code/Personal Projects/Dialogue-Driver/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dialogue_driver.dir/src/driver.cpp.obj"
	C:/TDM-GCC-64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dialogue_driver.dir/src/driver.cpp.obj -MF CMakeFiles/dialogue_driver.dir/src/driver.cpp.obj.d -o CMakeFiles/dialogue_driver.dir/src/driver.cpp.obj -c "D:/Documents/Code/Personal Projects/Dialogue-Driver/src/driver.cpp"

CMakeFiles/dialogue_driver.dir/src/driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dialogue_driver.dir/src/driver.cpp.i"
	C:/TDM-GCC-64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:/Documents/Code/Personal Projects/Dialogue-Driver/src/driver.cpp" > CMakeFiles/dialogue_driver.dir/src/driver.cpp.i

CMakeFiles/dialogue_driver.dir/src/driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dialogue_driver.dir/src/driver.cpp.s"
	C:/TDM-GCC-64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:/Documents/Code/Personal Projects/Dialogue-Driver/src/driver.cpp" -o CMakeFiles/dialogue_driver.dir/src/driver.cpp.s

# Object files for target dialogue_driver
dialogue_driver_OBJECTS = \
"CMakeFiles/dialogue_driver.dir/src/driver.cpp.obj"

# External object files for target dialogue_driver
dialogue_driver_EXTERNAL_OBJECTS =

libdialogue_driver.dll: CMakeFiles/dialogue_driver.dir/src/driver.cpp.obj
libdialogue_driver.dll: CMakeFiles/dialogue_driver.dir/build.make
libdialogue_driver.dll: CMakeFiles/dialogue_driver.dir/linkLibs.rsp
libdialogue_driver.dll: CMakeFiles/dialogue_driver.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:/Documents/Code/Personal Projects/Dialogue-Driver/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libdialogue_driver.dll"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/dialogue_driver.dir/objects.a
	C:/TDM-GCC-64/bin/ar.exe qc CMakeFiles/dialogue_driver.dir/objects.a @CMakeFiles/dialogue_driver.dir/objects1.rsp
	C:/TDM-GCC-64/bin/g++.exe -g -shared -o libdialogue_driver.dll -Wl,--out-implib,libdialogue_driver.dll.a -Wl,--major-image-version,0,--minor-image-version,0 -Wl,--whole-archive CMakeFiles/dialogue_driver.dir/objects.a -Wl,--no-whole-archive @CMakeFiles/dialogue_driver.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/dialogue_driver.dir/build: libdialogue_driver.dll
.PHONY : CMakeFiles/dialogue_driver.dir/build

CMakeFiles/dialogue_driver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dialogue_driver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dialogue_driver.dir/clean

CMakeFiles/dialogue_driver.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "D:/Documents/Code/Personal Projects/Dialogue-Driver" "D:/Documents/Code/Personal Projects/Dialogue-Driver" "D:/Documents/Code/Personal Projects/Dialogue-Driver/build" "D:/Documents/Code/Personal Projects/Dialogue-Driver/build" "D:/Documents/Code/Personal Projects/Dialogue-Driver/build/CMakeFiles/dialogue_driver.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/dialogue_driver.dir/depend
