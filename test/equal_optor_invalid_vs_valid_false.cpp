#include <gtest/gtest.h>
#include <rectangle.h>

// Equal operator
TEST(RectangleCaseTest, EqualOptor_InvalidVsValidFalse) {
	rectangle invalid;
	rectangle valid(1, 1, 1, 1);

	ASSERT_FALSE(invalid == valid);
}
