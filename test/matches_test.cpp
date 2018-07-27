#include <gtest/gtest.h>
#include <rectangles_matches.h>

// Just add a rectangle
TEST(RectanglesMatchesCaseTest, AddRectange) {
	rectangles_matches matches;
	rectangle inv;
	rectangle valid(10, 10, 10, 10);

	ASSERT_FALSE(matches.add_rectangle(inv));
	ASSERT_TRUE(matches.add_rectangle(valid));
}

// Operator << to make it easy to print the values
TEST(RectanglesMatchesCaseTest, OstreamOutOperator) {
	rectangles_matches matches;
	rectangle rect0(20, 10, 10, 10);
	rectangle rect1(10, 10, 10, 10);
	rectangle rect2(5, 5, 10, 10);

	matches.add_rectangle(rect0);
	ASSERT_STREQ(matches.to_string().c_str(), "Input:\n"
		                                      "\t1: Rectangle at (20, 10), w=10, h=10.\n");

	matches.add_rectangle(rect1);
	std::string s = matches.to_string();
	ASSERT_STREQ(matches.to_string().c_str(), "Input:\n"
	                                          "\t1: Rectangle at (20, 10), w=10, h=10.\n"
	                                          "\t2: Rectangle at (10, 10), w=10, h=10.\n");

	matches.add_rectangle(rect2);
	s = matches.to_string();
	ASSERT_STREQ(matches.to_string().c_str(), "Input:\n"
	                                          "\t1: Rectangle at (20, 10), w=10, h=10.\n"
	                                          "\t2: Rectangle at (10, 10), w=10, h=10.\n"
	                                          "\t3: Rectangle at (5, 5), w=10, h=10.\n\n"
	                                          "Intersections\n"
	                                          "\tBetween rectangle 2 and 3 at (10, 10), w=5, h=5.\n");
}



