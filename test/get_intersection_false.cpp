#include <gtest/gtest.h>
#include <rectangle.h>

// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST(RectangleCaseTest, GetIntersection_False) {
	rectangle rect1(20, 10, 10, 10);
	rectangle rect2(10, 10, 10, 10);

	// get_intersection return a shared_ptr to an invalid rectangle
	ASSERT_TRUE(!(rect1.get_intersection(rect2)));
}
