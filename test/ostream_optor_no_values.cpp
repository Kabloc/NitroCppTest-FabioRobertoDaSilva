#include <gtest/gtest.h>
#include <rectangle.h>

// Operator << to make it easy to print the values
TEST(RectangleCaseTest, OstreamOptor_NoValues) {
	rectangle rect;
	ASSERT_STREQ(rect.to_string().c_str(), "(0, 0), w=0, h=0");
}

