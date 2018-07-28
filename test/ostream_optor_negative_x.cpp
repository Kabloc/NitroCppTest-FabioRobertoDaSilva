#include <gtest/gtest.h>
#include <rectangle.h>

// Operator << to make it easy to print the values
TEST(RectangleCaseTest, OstreamOptor_NegativeX) {
	rectangle rect(-10, 10, 10, 10);
	ASSERT_STREQ(rect.to_string().c_str(), "(-10, 10), w=10, h=10");
}

