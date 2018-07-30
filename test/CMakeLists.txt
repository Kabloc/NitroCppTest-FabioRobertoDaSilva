project( nitro_rectangles_matches_test )

include_directories ( ${nitro_rectangles_matches_SOURCE_DIR}/include/ )
include_directories ( ${CMAKE_CURRENT_BINARY_DIR} )

add_executable(nitro_rectangles_matches_test ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                             ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangles_matches.cpp
                                             nitro_rectangles_matches_test.cpp)
							  
target_link_libraries(nitro_rectangles_matches_test gtest_main)

add_test(NAME RectangleMatchesTests
         COMMAND $<TARGET_FILE:nitro_rectangles_matches_test>)
