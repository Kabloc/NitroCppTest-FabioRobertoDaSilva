#include <gtest/gtest.h>
#include <rectangle.h>

// Operator << to make it easy to print the values
TEST(RectangleCaseTest, OstreamOptor_NoWidht) {
	rectangle rect(1, 1, 0, 1);
	ASSERT_STREQ(rect.to_string().c_str(), "(1, 1), w=0, h=1");
}

