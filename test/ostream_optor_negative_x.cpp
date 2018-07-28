#include <gtest/gtest.h>
#include <rectangle.h>

// Operator << to make it easy to print the values
TEST(RectangleCaseTest, OstreamOptor_NegativeX) {
	rectangle rect(-1, 1, 1, 1);
	ASSERT_STREQ(rect.to_string().c_str(), "(-1, 1), w=1, h=1");
}

