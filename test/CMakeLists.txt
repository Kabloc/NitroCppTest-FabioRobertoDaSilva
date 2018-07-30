project( nitro_rectangles_matches_test )

include_directories ( ${nitro_rectangles_matches_SOURCE_DIR}/include/ )
include_directories ( ${CMAKE_CURRENT_BINARY_DIR} )

add_executable(test_ctor_no_params ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                              ctor_no_params.cpp)
target_link_libraries(test_ctor_no_params gtest_main)
add_test(NAME Rectangle_Ctor_NoParams COMMAND test_ctor_no_params)

add_executable(test_ctor_ok ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                       ctor_ok.cpp)
target_link_libraries(test_ctor_ok gtest_main)
add_test(NAME Rectangle_Ctor_OK COMMAND test_ctor_ok)

add_executable(test_ctor_no_width ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                             ctor_no_width.cpp)
target_link_libraries(test_ctor_no_width gtest_main)
add_test(NAME Rectangle_Ctor_NoWidth COMMAND test_ctor_no_width)

add_executable(test_ctor_negative_height ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                    ctor_negative_height.cpp)
target_link_libraries(test_ctor_negative_height gtest_main)
add_test(NAME Rectangle_Ctor_NegativeWidth COMMAND test_ctor_negative_height)

add_executable(test_ctor_no_height ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                              ctor_no_height.cpp)
target_link_libraries(test_ctor_no_height gtest_main)
add_test(NAME Rectangle_Ctor_NoHeight COMMAND test_ctor_no_height)

add_executable(test_ctor_negative_width ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                   ctor_negative_width.cpp)
target_link_libraries(test_ctor_negative_width gtest_main)
add_test(NAME Rectangle_Ctor_NegativeHeight COMMAND test_ctor_negative_width)

add_executable(test_ctor_negative_x ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                               ctor_negative_x.cpp)
target_link_libraries(test_ctor_negative_x gtest_main)
add_test(NAME Rectangle_Ctor_NegativeX COMMAND test_ctor_negative_x)

add_executable(test_ctor_negative_y ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                               ctor_negative_y.cpp)
target_link_libraries(test_ctor_negative_y gtest_main)
add_test(NAME Rectangle_Ctor_NegativeY COMMAND test_ctor_negative_y)

add_executable(test_equal_optor_invalid_vs_invalid_true ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                                   equal_optor_invalid_vs_invalid_true.cpp)
target_link_libraries(test_equal_optor_invalid_vs_invalid_true gtest_main)
add_test(NAME Rectangle_EqualOptor_InvalidVsInvalidTrue COMMAND test_equal_optor_invalid_vs_invalid_true)

add_executable(test_equal_optor_valid_vs_valid_false ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                                equal_optor_valid_vs_valid_false.cpp)
target_link_libraries(test_equal_optor_valid_vs_valid_false gtest_main)
add_test(NAME Rectangle_EqualOptor_ValidVsValidTrue COMMAND test_equal_optor_valid_vs_valid_false)

add_executable(test_equal_optor_valid_vs_valid_true ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                               equal_optor_valid_vs_valid_true.cpp)
target_link_libraries(test_equal_optor_valid_vs_valid_true gtest_main)
add_test(NAME Rectangle_EqualOptor_ValidVsValidFalse COMMAND test_equal_optor_valid_vs_valid_true)

add_executable(test_equal_optor_invalid_vs_valid_false ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                                  equal_optor_invalid_vs_valid_false.cpp)
target_link_libraries(test_equal_optor_invalid_vs_valid_false gtest_main)
add_test(NAME Rectangle_EqualOptor_InvalidVsValidFalse COMMAND test_equal_optor_invalid_vs_valid_false)

add_executable(test_ostream_optor_ok ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                ostream_optor_ok.cpp)
target_link_libraries(test_ostream_optor_ok gtest_main)
add_test(NAME Rectangle_OstreamOptor_Ok COMMAND test_ostream_optor_ok)

add_executable(test_ostream_optor_no_values ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                       ostream_optor_no_values.cpp)
target_link_libraries(test_ostream_optor_no_values gtest_main)
add_test(NAME Rectangle_OstreamOptor_NoValues COMMAND test_ostream_optor_no_values)

add_executable(test_ostream_optor_no_widht ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                      ostream_optor_no_widht.cpp)
target_link_libraries(test_ostream_optor_no_widht gtest_main)
add_test(NAME Rectangle_OstreamOptor_NoWidht COMMAND test_ostream_optor_no_widht) 

add_executable(test_ostream_optor_negative_widht ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                      ostream_optor_negative_widht.cpp)
target_link_libraries(test_ostream_optor_negative_widht gtest_main)
add_test(NAME Rectangle_OstreamOptor_NegativeWidht COMMAND test_ostream_optor_negative_widht) 

add_executable(test_ostream_optor_no_height ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                       ostream_optor_no_height.cpp)
target_link_libraries(test_ostream_optor_no_height gtest_main)
add_test(NAME Rectangle_OstreamOptor_NoHeight COMMAND test_ostream_optor_no_height) 

add_executable(test_ostream_optor_negative_height ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                       ostream_optor_negative_height.cpp)
target_link_libraries(test_ostream_optor_negative_height gtest_main)
add_test(NAME Rectangle_OstreamOptor_NegativeHeight COMMAND test_ostream_optor_negative_height) 

add_executable(test_ostream_optor_negative_x ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                        ostream_optor_negative_x.cpp)
target_link_libraries(test_ostream_optor_negative_x gtest_main)
add_test(NAME Rectangle_OstreamOptor_NegativeX COMMAND test_ostream_optor_negative_x) 

add_executable(test_ostream_optor_negative_y ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                        ostream_optor_negative_y.cpp)
target_link_libraries(test_ostream_optor_negative_y gtest_main)
add_test(NAME Rectangle_OstreamOptor_NegativeY COMMAND test_ostream_optor_negative_y) 

add_executable(test_intersction_false ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                 intersction_false.cpp)
target_link_libraries(test_intersction_false gtest_main)
add_test(NAME Rectangle_Intersction_False COMMAND test_intersction_false)

add_executable(test_intersction_true ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                intersction_true.cpp)
target_link_libraries(test_intersction_true gtest_main)
add_test(NAME Rectangle_Intersction_True COMMAND test_intersction_true)

add_executable(test_get_intersection_false ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                      get_intersection_false.cpp)
target_link_libraries(test_get_intersection_false gtest_main)
add_test(NAME Rectangle_GetIntersection_False COMMAND test_get_intersection_false)

add_executable(test_get_intersection_false_limit_x ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                              get_intersection_false_limit_x.cpp)
target_link_libraries(test_get_intersection_false_limit_x gtest_main)
add_test(NAME Rectangle_GetIntersection_FalseLimitX COMMAND test_get_intersection_false_limit_x)

add_executable(test_get_intersection_false_limit_y ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                              get_intersection_false_limit_y.cpp)
target_link_libraries(test_get_intersection_false_limit_y gtest_main)
add_test(NAME Rectangle_GetIntersection_FalseLimitY COMMAND test_get_intersection_false_limit_y)

add_executable(test_get_intersection_true ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                     get_intersection_true.cpp)
target_link_libraries(test_get_intersection_true gtest_main)
add_test(NAME Rectangle_GetIntersection_True COMMAND test_get_intersection_true)

add_executable(test_get_intersection_true_limit_y ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                             get_intersection_true_limit_y.cpp)
target_link_libraries(test_get_intersection_true_limit_y gtest_main)
add_test(NAME Rectangle_GetIntersection_TrueLimitY COMMAND test_get_intersection_true_limit_y)

add_executable(test_get_intersection_true_limit_x ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                             get_intersection_true_limit_x.cpp)
target_link_libraries(test_get_intersection_true_limit_x gtest_main)
add_test(NAME Rectangle_GetIntersection_TrueLimitX COMMAND test_get_intersection_true_limit_x)

add_executable(test_get_intersection_true_verified ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                              get_intersection_true_verified.cpp)
target_link_libraries(test_get_intersection_true_verified gtest_main)
add_test(NAME Rectangle_GetIntersection_TrueVerified COMMAND test_get_intersection_true_verified)

add_executable(test_add_rectange_valid ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                  ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangles_matches.cpp
                                  add_rectange_valid.cpp)
target_link_libraries(test_add_rectange_valid gtest_main)
add_test(NAME RectanglesMatches_AddRectange_Valid COMMAND test_add_rectange_valid)

add_executable(test_add_rectange_invalid ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                    ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangles_matches.cpp
                                    add_rectange_invalid.cpp)
target_link_libraries(test_add_rectange_invalid gtest_main)
add_test(NAME RectanglesMatches_AddRectange_Invalid COMMAND test_add_rectange_invalid)


add_executable(test_ostream_operator_1 ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                  ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangles_matches.cpp
                                  ostream_operator_1.cpp)
target_link_libraries(test_ostream_operator_1 gtest_main)
add_test(NAME RectanglesMatches_OstreamOperator_1 COMMAND test_ostream_operator_1)

add_executable(test_ostream_operator_2 ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                  ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangles_matches.cpp
                                  ostream_operator_2.cpp)
target_link_libraries(test_ostream_operator_2 gtest_main)
add_test(NAME RectanglesMatches_OstreamOperator_2 COMMAND test_ostream_operator_2)

add_executable(test_ostream_operator_3 ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangle.cpp
                                  ${nitro_rectangles_matches_SOURCE_DIR}/src/rectangles_matches.cpp
                                  ostream_operator_3.cpp)
target_link_libraries(test_ostream_operator_3 gtest_main)
add_test(NAME RectanglesMatches_OstreamOperator_3 COMMAND test_ostream_operator_3)
