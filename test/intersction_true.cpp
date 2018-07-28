#include <gtest/gtest.h>
#include <rectangle.h>

// Used to verify if exist a valid intersection rectangle
// between this and another rectangle.
TEST(RectangleCaseTest, Intersction_True) {
	rectangle rect1(10, 10, 10, 10);
	rectangle rect2(5, 5, 10, 10);

	ASSERT_TRUE(rect1.intersect(rect2));
}
