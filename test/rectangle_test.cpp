#include <gtest/gtest.h>
#include <rectangle.h>


// Default contructor will create a invalid rectangle
// Parametized constructor will create a rectangle and verify if
// it is sized: 
// "Width and height are always positive integers" - from Purpose file
TEST(RectangleCaseTest, Ctor_OperatorBool) {
	rectangle rect0;
	rectangle rect1(10, 10, 10, 10);
	rectangle rect2(10, 10, 0, 10);
	rectangle rect3(10, 10, 10, 0);
	rectangle rect4(-10, 10, 10, 10);
	rectangle rect5(10, -10, 10, 10);

	ASSERT_TRUE(!rect0);
	ASSERT_FALSE(!rect1);
	ASSERT_TRUE(!rect2);
	ASSERT_TRUE(!rect3);
	ASSERT_FALSE(!rect4);
	ASSERT_FALSE(!rect5);
}

// Equal operator
TEST(RectangleCaseTest, EqualOperator) {
	rectangle inv_a;
	rectangle inv_b;
	rectangle valid_a(10, 10, 10, 10);
	rectangle valid_b(10, 10, 10, 10);
	rectangle valid_x(20, 20, 20, 20);

	ASSERT_TRUE(inv_a == inv_b);
	ASSERT_TRUE(valid_a == valid_b);
	ASSERT_FALSE(valid_a == valid_x);
	ASSERT_FALSE(inv_a == valid_a);
}

// Operator << to make it easy to print the values
TEST(RectangleCaseTest, OstreamOutOperator) {
	rectangle rect0;
	rectangle rect1(10, 10, 10, 10);
	rectangle rect2(10, 10, 0, 10);
	rectangle rect3(10, 10, 10, 0);
	rectangle rect4(-10, 10, 10, 10);
	rectangle rect5(10, -10, 10, 10);

	ASSERT_STREQ(rect0.to_string().c_str(), "(0, 0), w=0, h=0");
	ASSERT_STREQ(rect1.to_string().c_str(), "(10, 10), w=10, h=10");
	ASSERT_STREQ(rect2.to_string().c_str(), "(10, 10), w=0, h=10");
	ASSERT_STREQ(rect3.to_string().c_str(), "(10, 10), w=10, h=0");
	ASSERT_STREQ(rect4.to_string().c_str(), "(-10, 10), w=10, h=10");
	ASSERT_STREQ(rect5.to_string().c_str(), "(10, -10), w=10, h=10");
}

// Used to verify if exist a valid intersection rectangle
// between this and another rectangle.
TEST(RectangleCaseTest, Intersction) {
	rectangle rect0(20, 10, 10, 10);
	rectangle rect1(10, 10, 10, 10);
	rectangle rect2(5, 5, 10, 10);

	ASSERT_FALSE(rect0.intersect(rect1));
	ASSERT_TRUE(rect1.intersect(rect2));
}

// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST(RectangleCaseTest, GetIntersection) {
	rectangle rect0(20, 10, 10, 10);
	rectangle rect1(10, 10, 10, 10);
	rectangle rect2(5, 5, 10, 10);

	// get_intersection return a shared_ptr to an invalid rectangle
	ASSERT_TRUE(!(rect0.get_intersection(rect1)));

	// get_intersection return a shared_ptr to a valid rectangle
	ASSERT_FALSE(!(rect1.get_intersection(rect2)));

	// The rectangle returned by get_intersection should have this values
	ASSERT_STREQ((rect1.get_intersection(rect2)).to_string().c_str(), "(10, 10), w=5, h=5");
}
