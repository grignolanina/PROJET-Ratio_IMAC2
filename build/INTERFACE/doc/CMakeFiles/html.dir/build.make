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
CMAKE_SOURCE_DIR = /WindowsData/Users/Nina/Documents/IMAC/COURS/2A/Programmation_objet/projet/Ratio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /WindowsData/Users/Nina/Documents/IMAC/COURS/2A/Programmation_objet/projet/Ratio/build

# Utility rule file for html.

# Include the progress variables for this target.
include INTERFACE/doc/CMakeFiles/html.dir/progress.make

INTERFACE/doc/CMakeFiles/html:
	cd /WindowsData/Users/Nina/Documents/IMAC/COURS/2A/Programmation_objet/projet/Ratio/build/INTERFACE/doc && /usr/bin/doxygen /WindowsData/Users/Nina/Documents/IMAC/COURS/2A/Programmation_objet/projet/Ratio/build/INTERFACE/doc/Doxyfile-html

html: INTERFACE/doc/CMakeFiles/html
html: INTERFACE/doc/CMakeFiles/html.dir/build.make

.PHONY : html

# Rule to build all files generated by this target.
INTERFACE/doc/CMakeFiles/html.dir/build: html

.PHONY : INTERFACE/doc/CMakeFiles/html.dir/build

INTERFACE/doc/CMakeFiles/html.dir/clean:
	cd /WindowsData/Users/Nina/Documents/IMAC/COURS/2A/Programmation_objet/projet/Ratio/build/INTERFACE/doc && $(CMAKE_COMMAND) -P CMakeFiles/html.dir/cmake_clean.cmake
.PHONY : INTERFACE/doc/CMakeFiles/html.dir/clean

INTERFACE/doc/CMakeFiles/html.dir/depend:
	cd /WindowsData/Users/Nina/Documents/IMAC/COURS/2A/Programmation_objet/projet/Ratio/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /WindowsData/Users/Nina/Documents/IMAC/COURS/2A/Programmation_objet/projet/Ratio /WindowsData/Users/Nina/Documents/IMAC/COURS/2A/Programmation_objet/projet/Ratio/myLib/doc /WindowsData/Users/Nina/Documents/IMAC/COURS/2A/Programmation_objet/projet/Ratio/build /WindowsData/Users/Nina/Documents/IMAC/COURS/2A/Programmation_objet/projet/Ratio/build/INTERFACE/doc /WindowsData/Users/Nina/Documents/IMAC/COURS/2A/Programmation_objet/projet/Ratio/build/INTERFACE/doc/CMakeFiles/html.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : INTERFACE/doc/CMakeFiles/html.dir/depend

