#include <gtest/gtest.h>
#include <rectangle.h>

// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST(RectangleCaseTest, GetIntersection_True) {
	rectangle rect1(0, 0, 2, 2);
	rectangle rect2(1, 1, 2, 2);

	// get_intersection return a shared_ptr to a valid rectangle
	ASSERT_FALSE(!(*rect1.get_intersection(rect2)));
}
