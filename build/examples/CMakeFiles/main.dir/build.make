# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pauline/Documents/S3/c++/PROJET/Ratio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pauline/Documents/S3/c++/PROJET/Ratio/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/main.dir/flags.make

examples/CMakeFiles/main.dir/src/main.cpp.o: examples/CMakeFiles/main.dir/flags.make
examples/CMakeFiles/main.dir/src/main.cpp.o: ../examples/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pauline/Documents/S3/c++/PROJET/Ratio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/main.dir/src/main.cpp.o"
	cd /home/pauline/Documents/S3/c++/PROJET/Ratio/build/examples && /bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/main.cpp.o -c /home/pauline/Documents/S3/c++/PROJET/Ratio/examples/src/main.cpp

examples/CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	cd /home/pauline/Documents/S3/c++/PROJET/Ratio/build/examples && /bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pauline/Documents/S3/c++/PROJET/Ratio/examples/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

examples/CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	cd /home/pauline/Documents/S3/c++/PROJET/Ratio/build/examples && /bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pauline/Documents/S3/c++/PROJET/Ratio/examples/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

bin/main: examples/CMakeFiles/main.dir/src/main.cpp.o
bin/main: examples/CMakeFiles/main.dir/build.make
bin/main: INTERFACE/libRatio.a
bin/main: examples/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pauline/Documents/S3/c++/PROJET/Ratio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/main"
	cd /home/pauline/Documents/S3/c++/PROJET/Ratio/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/main.dir/build: bin/main

.PHONY : examples/CMakeFiles/main.dir/build

examples/CMakeFiles/main.dir/clean:
	cd /home/pauline/Documents/S3/c++/PROJET/Ratio/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/main.dir/clean

examples/CMakeFiles/main.dir/depend:
	cd /home/pauline/Documents/S3/c++/PROJET/Ratio/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pauline/Documents/S3/c++/PROJET/Ratio /home/pauline/Documents/S3/c++/PROJET/Ratio/examples /home/pauline/Documents/S3/c++/PROJET/Ratio/build /home/pauline/Documents/S3/c++/PROJET/Ratio/build/examples /home/pauline/Documents/S3/c++/PROJET/Ratio/build/examples/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/main.dir/depend
