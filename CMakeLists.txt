cmake_minimum_required(VERSION 3.0)
project (nitro_rectangles_matches)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include("cmake/googletest.cmake")

enable_testing()
add_subdirectory(src)
add_subdirectory(test)