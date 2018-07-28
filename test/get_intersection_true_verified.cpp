#include <gtest/gtest.h>
#include <rectangle.h>

// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST(RectangleCaseTest, GetIntersection_TrueVerified) {
	rectangle rect1(0, 0, 2, 2);
	rectangle rect2(1, 1, 2, 2);

	// The rectangle returned by get_intersection should have this values
	ASSERT_STREQ((rect1.get_intersection(rect2)).to_string().c_str(), "(1, 1), w=1, h=1");
}
