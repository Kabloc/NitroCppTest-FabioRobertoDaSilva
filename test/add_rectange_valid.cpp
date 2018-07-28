#include <gtest/gtest.h>
#include <rectangles_matches.h>

// Just add a rectangle
TEST(RectanglesMatchesCaseTest, AddRectange_Valid) {
	rectangles_matches matches;
	rectangle valid(10, 10, 10, 10);

	ASSERT_TRUE(matches.add_rectangle(valid));
}

