#include <gtest/gtest.h>
#include <rectangle.h>

// Operator << to make it easy to print the values
TEST(RectangleCaseTest, OstreamOptor_NoWidht) {
	rectangle rect(10, 10, 0, 10);
	ASSERT_STREQ(rect.to_string().c_str(), "(10, 10), w=0, h=10");
}

