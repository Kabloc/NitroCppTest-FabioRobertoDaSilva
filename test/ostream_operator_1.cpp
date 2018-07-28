#include <gtest/gtest.h>
#include <rectangles_matches.h>

// Operator << to make it easy to print the values
TEST(RectanglesMatchesCaseTest, OstreamOperator_1) {
	rectangles_matches matches;
	rectangle rect(3, 1, 2, 2);

	matches.add_rectangle(rect);
	ASSERT_STREQ(matches.to_string().c_str(), "Input:\n"
		                                      "\t1: Rectangle at (3, 1), w=2, h=2.\n");
}

