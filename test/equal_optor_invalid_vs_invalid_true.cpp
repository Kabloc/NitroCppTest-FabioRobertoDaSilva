#include <gtest/gtest.h>
#include <rectangle.h>

// Equal operator
TEST(RectangleCaseTest, EqualOptor_InvalidVsInvalidTrue) {
	rectangle invalid_a;
	rectangle invalid_b;

	ASSERT_TRUE(invalid_a == invalid_b);
}
