#include <gtest/gtest.h>
#include <rectangles_matches.h>

// Operator << to make it easy to print the values
TEST(RectanglesMatchesCaseTest, OstreamOperator_3) {
	rectangles_matches matches;
	rectangle rect1(3, 1, 2, 2);
	rectangle rect2(1, 1, 2, 2);
	rectangle rect3(0, 0, 2, 2);

	matches.add_rectangle(rect1);
	matches.add_rectangle(rect2);
	matches.add_rectangle(rect3);
	ASSERT_STREQ(matches.to_string().c_str(), "Input:\n"
	                                          "\t1: Rectangle at (3, 1), w=2, h=2.\n"
	                                          "\t2: Rectangle at (1, 1), w=2, h=2.\n"
	                                          "\t3: Rectangle at (0, 0), w=2, h=2.\n\n"
	                                          "Intersections\n"
	                                          "\tBetween rectangle 2 and 3 at (1, 1), w=1, h=1.\n");
}

