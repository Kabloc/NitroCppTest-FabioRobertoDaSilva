#include <gtest/gtest.h>
#include <rectangle.h>

// Default contructor will create a invalid rectangle
TEST(RectangleCaseTest, Ctor_NoParams) {
	rectangle rect;
	ASSERT_TRUE(!rect);
}