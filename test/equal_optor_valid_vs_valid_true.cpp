#include <gtest/gtest.h>
#include <rectangle.h>

// Equal operator
TEST(RectangleCaseTest, EqualOptor_ValidVsValidTrue) {
	rectangle valid_a(10, 10, 10, 10);
	rectangle valid_b(10, 10, 10, 10);

	ASSERT_TRUE(valid_a == valid_b);
}
