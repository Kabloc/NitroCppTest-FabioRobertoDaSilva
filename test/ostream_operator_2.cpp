#include <gtest/gtest.h>
#include <rectangles_matches.h>

// Operator << to make it easy to print the values
TEST(RectanglesMatchesCaseTest, OstreamOperator_2) {
	rectangles_matches matches;
	rectangle rect1(3, 1, 2, 2);
	rectangle rect2(1, 1, 2, 2);

	matches.add_rectangle(rect1);
	matches.add_rectangle(rect2);
	ASSERT_STREQ(matches.to_string().c_str(), "Input:\n"
	                                          "\t1: Rectangle at (3, 1), w=2, h=2.\n"
	                                          "\t2: Rectangle at (1, 1), w=2, h=2.\n");

}

