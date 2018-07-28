#include <gtest/gtest.h>
#include <rectangle.h>

// Equal operator
TEST(RectangleCaseTest, EqualOptor_ValidVsValidTrue) {
	rectangle valid_a(1, 1, 1, 1);
	rectangle valid_b(1, 1, 1, 1);

	ASSERT_TRUE(valid_a == valid_b);
}
