#include <gtest/gtest.h>
#include <rectangle.h>

// Parametized constructor will create a rectangle and verify if it is sized: 
// "Width and height are always positive integers" - from Purpose file
TEST(RectangleCaseTest, Ctor_NegativeHeight) {
	rectangle rect(1, 1, 1, -1);
	ASSERT_TRUE(!rect);
}
