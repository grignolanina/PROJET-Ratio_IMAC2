cmake_minimum_required(VERSION 3.13)

enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(myUnitTests src/mainTest.cpp)
target_link_libraries(myUnitTests PUBLIC Ratio GTest::GTest GTest::Main)
target_include_directories(myUnitTests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )
target_compile_features(myUnitTests PRIVATE cxx_std_17)

gtest_discover_tests(myUnitTests)



