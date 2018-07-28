#include <gtest/gtest.h>
#include <rectangle.h>

// Equal operator
TEST(RectangleCaseTest, EqualOptor_ValidVsValidFalse) {
	rectangle valid_a(0, 0, 1, 1);
	rectangle valid_b(1, 1, 1, 1);

	ASSERT_FALSE(valid_a == valid_b);
}
