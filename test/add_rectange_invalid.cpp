#include <gtest/gtest.h>
#include <rectangles_matches.h>

// Just add a rectangle
TEST(RectanglesMatchesCaseTest, AddRectange_Invalid) {
	rectangles_matches matches;
	rectangle inv;

	ASSERT_FALSE(matches.add_rectangle(inv));
}

