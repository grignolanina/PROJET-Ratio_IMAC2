cmake_minimum_required(VERSION 3.13)

project(ratioProject)



set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/output)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)



message(STATUS "myLib cmake part ..." )
add_subdirectory(myLib INTERFACE)
include_directories(${CMAKE_SOURCE_DIR}/myLib/include) 

message(STATUS "examples cmake part ..." )
add_subdirectory(examples)

find_package(GTest OPTIONAL_COMPONENTS)
if(GTEST_FOUND)
	message(STATUS "myTest cmake part ..." )
	add_subdirectory(myTest)
elseif()
	message(WARNING "google test not found, skipping myTest ..." )
endif()
