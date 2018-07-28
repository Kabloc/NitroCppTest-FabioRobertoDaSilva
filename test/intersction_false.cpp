#include <gtest/gtest.h>
#include <rectangle.h>

// Used to verify if exist a valid intersection rectangle
// between this and another rectangle.
TEST(RectangleCaseTest, Intersction_False) {
	rectangle rect1(20, 10, 10, 10);
	rectangle rect2(10, 10, 10, 10);

	ASSERT_FALSE(rect1.intersect(rect2));
}
