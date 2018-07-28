#include <gtest/gtest.h>
#include <rectangles_matches.h>

// Operator << to make it easy to print the values
TEST(RectanglesMatchesCaseTest, OstreamOperator_1) {
	rectangles_matches matches;
	rectangle rect(20, 10, 10, 10);

	matches.add_rectangle(rect);
	ASSERT_STREQ(matches.to_string().c_str(), "Input:\n"
		                                      "\t1: Rectangle at (20, 10), w=10, h=10.\n");
}

