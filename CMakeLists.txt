cmake_minimum_required(VERSION 3.10)
project (nitro_test)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

add_executable (nitro_test main.cpp)
target_link_libraries (nitro_test ${CMAKE_THREAD_LIBS_INIT})
