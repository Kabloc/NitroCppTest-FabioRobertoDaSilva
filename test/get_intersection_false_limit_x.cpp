#include <gtest/gtest.h>
#include <rectangle.h>

// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST(RectangleCaseTest, GetIntersection_FalseLimitX) {
	rectangle rect1(0, 0, 2, 2);
	rectangle rect2(2, 0, 2, 2);

	// get_intersection return a shared_ptr to an invalid rectangle
	ASSERT_TRUE(!(*rect1.get_intersection(rect2)));
}
