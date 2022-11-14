cmake_minimum_required(VERSION 3.13)


# give a name to the project
project(myCmakeTest)

# display VERBOSE messages : cmake --log-level=VERBOSE ..

# specify the system
message(VERBOSE "CMAKE_VERSION           : " ${CMAKE_VERSION})
message(VERBOSE "CMAKE_SYSTEM_NAME       : " ${CMAKE_SYSTEM_NAME})
message(VERBOSE "CMAKE_SYSTEM            : " ${CMAKE_SYSTEM})
message(VERBOSE "CMAKE_SYSTEM_PROCESSOR  : " ${CMAKE_SYSTEM_PROCESSOR} "\n")

# specify the directories
message(VERBOSE "CMAKE_BINARY_DIR        : " ${CMAKE_BINARY_DIR})
message(VERBOSE "CMAKE_SOURCE_DIR        : " ${CMAKE_SOURCE_DIR})
message(VERBOSE "CMAKE_HOME_DIRECTORY    : " ${CMAKE_HOME_DIRECTORY})
message(VERBOSE "PROJECT_BINARY_DIR      : " ${PROJECT_BINARY_DIR})
message(VERBOSE "PROJECT_SOURCE_DIR      : " ${PROJECT_SOURCE_DIR} "\n")

# compile flags
message(VERBOSE "CMAKE_CXX_FLAGS         : " ${CMAKE_CXX_FLAG})
message(VERBOSE "CMAKE_CXX_FLAGS_DEBUG   : " ${CMAKE_CXX_FLAGS_DEBUG})
message(VERBOSE "CMAKE_CXX_FLAGS_RELEASE : " ${CMAKE_CXX_FLAGS_RELEASE})
message(VERBOSE "CMAKE_CXX_COMPILER      : " ${CMAKE_CXX_COMPILER} "\n")


# not clear to me, but vscode can't work fine without
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Prevents compiler-specific extensions to C++ because they might allow code to compile on your machine but not on other people's machine
#set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

# (optional) add a "output" directory in the project binary directory (build)
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/output)

# (optional) put the binary files in this directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


##  va dans le dossier myCode1 et le cmake la bas te dira quoi faire
# add myCode1
message(STATUS "myCode1 cmake part ..." )
add_subdirectory(myCode1)

# add myLib
message(STATUS "myLib cmake part ..." )
add_subdirectory(myLib INTERFACE)
## au fait j'ai pas que des projets indépendants, j'ai aussi une lib personnelle
## je veux l'utiliser dans tout mon projet
## tout le projet qui seront dans des les dossiers enfants (comme la lib) connaitrons la librairie que je donne dans la ligne du dessous
include_directories(${CMAKE_SOURCE_DIR}/myLib/include) # important : other projects called by this cmake will know this include directory

