include_directories ( ${nitro_test_SOURCE_DIR}/include/ )
include_directories ( ${CMAKE_CURRENT_BINARY_DIR} )

add_executable(rect_test ${nitro_test_SOURCE_DIR}/src/rectangle.cpp
                         rectangle_test.cpp)

target_link_libraries(rect_test gtest_main)

add_executable(matches_test ${nitro_test_SOURCE_DIR}/src/rectangle.cpp
                            ${nitro_test_SOURCE_DIR}/src/rectangles_matches.cpp
                            matches_test.cpp)

target_link_libraries(matches_test gtest_main)