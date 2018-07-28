include_directories ( ${nitro_rectangles_matches_SOURCE_DIR}/include/ )
include_directories ( ${CMAKE_CURRENT_BINARY_DIR} )

add_executable(ctor_no_params ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                              ctor_no_params.cpp)
target_link_libraries(ctor_no_params gtest_main)
add_test(NAME Rectangle_Ctor_NoParams COMMAND ctor_no_params)

add_executable(ctor_ok ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                       ctor_ok.cpp)
target_link_libraries(ctor_ok gtest_main)
add_test(NAME Rectangle_Ctor_OK COMMAND ctor_ok)

add_executable(ctor_no_width ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                             ctor_no_width.cpp)
target_link_libraries(ctor_no_width gtest_main)
add_test(NAME Rectangle_Ctor_NoWidth COMMAND ctor_no_width)

add_executable(ctor_no_height ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                              ctor_no_height.cpp)
target_link_libraries(ctor_no_height gtest_main)
add_test(NAME Rectangle_Ctor_NoHeight COMMAND ctor_no_height)

add_executable(ctor_negative_x ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                               ctor_negative_x.cpp)
target_link_libraries(ctor_negative_x gtest_main)
add_test(NAME Rectangle_Ctor_NegativeX COMMAND ctor_negative_x)

add_executable(ctor_negative_y ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                               ctor_negative_y.cpp)
target_link_libraries(ctor_negative_y gtest_main)
add_test(NAME Rectangle_Ctor_NegativeY COMMAND ctor_negative_y)

add_executable(equal_optor_invalid_vs_invalid_true ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                                   equal_optor_invalid_vs_invalid_true.cpp)
target_link_libraries(equal_optor_invalid_vs_invalid_true gtest_main)
add_test(NAME Rectangle_EqualOptor_InvalidVsInvalidTrue COMMAND equal_optor_invalid_vs_invalid_true)

add_executable(equal_optor_valid_vs_valid_false ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                                equal_optor_valid_vs_valid_false.cpp)
target_link_libraries(equal_optor_valid_vs_valid_false gtest_main)
add_test(NAME Rectangle_EqualOptor_ValidVsValidTrue COMMAND equal_optor_valid_vs_valid_false)

add_executable(equal_optor_valid_vs_valid_true ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                               equal_optor_valid_vs_valid_true.cpp)
target_link_libraries(equal_optor_valid_vs_valid_true gtest_main)
add_test(NAME Rectangle_EqualOptor_ValidVsValidFalse COMMAND equal_optor_valid_vs_valid_true)

add_executable(equal_optor_invalid_vs_valid_false ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                                  equal_optor_invalid_vs_valid_false.cpp)
target_link_libraries(equal_optor_invalid_vs_valid_false gtest_main)
add_test(NAME Rectangle_EqualOptor_InvalidVsValidFalse COMMAND equal_optor_invalid_vs_valid_false)

add_executable(ostream_optor_ok ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                ostream_optor_ok.cpp)
target_link_libraries(ostream_optor_ok gtest_main)
add_test(NAME Rectangle_OstreamOptor_Ok COMMAND ostream_optor_ok)

add_executable(ostream_optor_no_values ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                       ostream_optor_no_values.cpp)
target_link_libraries(ostream_optor_no_values gtest_main)
add_test(NAME Rectangle_OstreamOptor_NoValues COMMAND ostream_optor_no_values)

add_executable(ostream_optor_no_widht ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                      ostream_optor_no_widht.cpp)
target_link_libraries(ostream_optor_no_widht gtest_main)
add_test(NAME Rectangle_OstreamOptor_NoWidht COMMAND ostream_optor_no_widht) 

add_executable(ostream_optor_no_height ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                       ostream_optor_no_height.cpp)
target_link_libraries(ostream_optor_no_height gtest_main)
add_test(NAME Rectangle_OstreamOptor_NoHeight COMMAND ostream_optor_no_height) 

add_executable(ostream_optor_negative_x ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                        ostream_optor_negative_x.cpp)
target_link_libraries(ostream_optor_negative_x gtest_main)
add_test(NAME Rectangle_OstreamOptor_NegativeX COMMAND ostream_optor_negative_x) 

add_executable(ostream_optor_negative_y ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                        ostream_optor_negative_y.cpp)
target_link_libraries(ostream_optor_negative_y gtest_main)
add_test(NAME Rectangle_OstreamOptor_NegativeY COMMAND ostream_optor_negative_y) 

add_executable(intersction_false ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                 intersction_false.cpp)
target_link_libraries(intersction_false gtest_main)
add_test(NAME Rectangle_Intersction_False COMMAND intersction_false)

add_executable(intersction_true ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                intersction_true.cpp)
target_link_libraries(intersction_true gtest_main)
add_test(NAME Rectangle_Intersction_True COMMAND intersction_true)

add_executable(get_intersection_false ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                      get_intersection_false.cpp)
target_link_libraries(get_intersection_false gtest_main)
add_test(NAME Rectangle_GetIntersection_False COMMAND get_intersection_false)

add_executable(get_intersection_true ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                     get_intersection_true.cpp)
target_link_libraries(get_intersection_true gtest_main)
add_test(NAME Rectangle_GetIntersection_True COMMAND get_intersection_true)

add_executable(get_intersection_true_verified ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                              get_intersection_true_verified.cpp)
target_link_libraries(get_intersection_true_verified gtest_main)
add_test(NAME Rectangle_GetIntersection_TrueVerified COMMAND get_intersection_true_verified)

add_executable(add_rectange_valid ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                  ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangles_matches.cpp
                                  add_rectange_valid.cpp)
target_link_libraries(add_rectange_valid gtest_main)
add_test(NAME RectanglesMatches_AddRectange_Valid COMMAND add_rectange_valid)

add_executable(add_rectange_invalid ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                    ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangles_matches.cpp
                                    add_rectange_invalid.cpp)
target_link_libraries(add_rectange_invalid gtest_main)
add_test(NAME RectanglesMatches_AddRectange_Invalid COMMAND add_rectange_invalid)


add_executable(ostream_operator_1 ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                  ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangles_matches.cpp
                                  ostream_operator_1.cpp)
target_link_libraries(ostream_operator_1 gtest_main)
add_test(NAME RectanglesMatches_OstreamOperator_1 COMMAND ostream_operator_1)

add_executable(ostream_operator_2 ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                  ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangles_matches.cpp
                                  ostream_operator_2.cpp)
target_link_libraries(ostream_operator_2 gtest_main)
add_test(NAME RectanglesMatches_OstreamOperator_2 COMMAND ostream_operator_2)

add_executable(ostream_operator_3 ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                  ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangles_matches.cpp
                                  ostream_operator_3.cpp)
target_link_libraries(ostream_operator_3 gtest_main)
add_test(NAME RectanglesMatches_OstreamOperator_3 COMMAND ostream_operator_3)
