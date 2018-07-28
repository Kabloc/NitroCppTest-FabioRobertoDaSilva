#include <gtest/gtest.h>
#include <rectangle.h>

// Used to verify if exist a valid intersection rectangle
// between this and another rectangle.
TEST(RectangleCaseTest, Intersction_False) {
	rectangle rect1(1, 0, 1, 1);
	rectangle rect2(0, 0, 1, 1);

	ASSERT_FALSE(rect1.intersect(rect2));
}
