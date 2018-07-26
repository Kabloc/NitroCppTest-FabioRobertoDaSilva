cmake_minimum_required(VERSION 3.0)
project (nitro_test)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

include_directories ( ${nitro_test_SOURCE_DIR}/include/ )

if(NOT EXISTS "${nitro_test_SOURCE_DIR}/include/json.hpp")
	message ( "Downloading json.hpp from 'JSON for Modern C++' project version 3.1.2" )
	file (DOWNLOAD "https://github.com/nlohmann/json/releases/download/v3.1.2/json.hpp" ${nitro_test_SOURCE_DIR}/include/json.hpp)
endif()

add_executable (nitro_test src/rectangle.cpp
                           src/rectangles_mactches.cpp
                           main.cpp)