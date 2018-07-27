cmake_minimum_required(VERSION 3.0)
project (nitro_test)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include("cmake/googletest.cmake")

enable_testing()
add_subdirectory(src)
add_subdirectory(test)

add_test(NAME Rectangle COMMAND rect_test)
add_test(NAME Rectangles_Matches COMMAND matches_test)