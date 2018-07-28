#include <gtest/gtest.h>
#include <rectangles_matches.h>

// Operator << to make it easy to print the values
TEST(RectanglesMatchesCaseTest, OstreamOperator_2) {
	rectangles_matches matches;
	rectangle rect1(20, 10, 10, 10);
	rectangle rect2(10, 10, 10, 10);

	matches.add_rectangle(rect1);
	matches.add_rectangle(rect2);
	ASSERT_STREQ(matches.to_string().c_str(), "Input:\n"
	                                          "\t1: Rectangle at (20, 10), w=10, h=10.\n"
	                                          "\t2: Rectangle at (10, 10), w=10, h=10.\n");

}

