#include <gtest/gtest.h>
#include <rectangle.h>

// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST(RectangleCaseTest, GetIntersection_TrueVerified) {
	rectangle rect1(10, 10, 10, 10);
	rectangle rect2(5, 5, 10, 10);

	// The rectangle returned by get_intersection should have this values
	ASSERT_STREQ((rect1.get_intersection(rect2)).to_string().c_str(), "(10, 10), w=5, h=5");
}
