cmake_minimum_required(VERSION 3.13)

project(example)

file(GLOB_RECURSE src_files_list src/*.cpp)

foreach(src_file ${src_files_list})

    get_filename_component(file_exe ${src_file} NAME_WE)    
    add_executable(${file_exe} ${src_file})                 
    target_link_libraries(${file_exe} PRIVATE Ratio)      
    target_compile_features(${file_exe} PRIVATE cxx_std_17)
    if (MSVC)
        target_compile_options(${file_exe} PRIVATE /W3)
    else()
        target_compile_options(${file_exe} PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
    endif()

    message(STATUS "src file  " ${src_file})
    message(STATUS "exe file  " ${file_exe})

endforeach()