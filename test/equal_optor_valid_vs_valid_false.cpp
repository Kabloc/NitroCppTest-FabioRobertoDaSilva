#include <gtest/gtest.h>
#include <rectangle.h>

// Equal operator
TEST(RectangleCaseTest, EqualOptor_ValidVsValidFalse) {
	rectangle valid_a(10, 10, 10, 10);
	rectangle valid_b(20, 20, 20, 20);

	ASSERT_FALSE(valid_a == valid_b);
}
