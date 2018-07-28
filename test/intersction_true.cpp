#include <gtest/gtest.h>
#include <rectangle.h>

// Used to verify if exist a valid intersection rectangle
// between this and another rectangle.
TEST(RectangleCaseTest, Intersction_True) {
	rectangle rect1(1, 1, 2, 2);
	rectangle rect2(0, 0, 2, 2);

	ASSERT_TRUE(rect1.intersect(rect2));
}
