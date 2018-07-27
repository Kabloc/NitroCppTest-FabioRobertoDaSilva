include_directories ( ${nitro_test_SOURCE_DIR}/include/ )
include_directories ( ${CMAKE_CURRENT_BINARY_DIR} )

if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/json.hpp")
	message ( "Downloading json.hpp from 'JSON for Modern C++' project version 3.1.2" )
	file (DOWNLOAD "https://github.com/nlohmann/json/releases/download/v3.1.2/json.hpp" ${CMAKE_CURRENT_BINARY_DIR}/json.hpp)
endif()

add_executable (nitro_test rectangle.cpp
                           rectangles_matches.cpp
                           main.cpp)