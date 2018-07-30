#include <gtest/gtest.h>
#include <rectangles_matches.h>

struct Tester : public ::testing::Test {
    virtual void SetUp() {
        fails = 0;
    }

    virtual void TearDown() {
        if (fails > 0) {
            std::cerr << "Tester::TearDown sees failures" << std::endl;
        }
    }

    unsigned fails;

};

// Just add a rectangle
TEST_F(Tester, AddRectange_Invalid) {
	rectangles_matches matches;
	rectangle inv;

	ASSERT_FALSE(!matches.add_rectangle(inv));
	fails += ::testing::Test::HasFailure();
}

// Just add a rectangle
TEST_F(Tester, AddRectange_Valid) {
	rectangles_matches matches;
	rectangle valid(10, 10, 10, 10);

	ASSERT_TRUE(!matches.add_rectangle(valid));
	fails += ::testing::Test::HasFailure();
}

// Parametized constructor will create a rectangle and verify if it is sized: 
// "Width and height are always positive integers" - from Purpose file
TEST_F(Tester, Ctor_NegativeHeight) {
	rectangle rect(1, 1, 1, -1);
	ASSERT_TRUE(!rect);
	fails += ::testing::Test::HasFailure();
}

// Parametized constructor will create a rectangle and verify if it is sized: 
// "Width and height are always positive integers" - from Purpose file
TEST_F(Tester, Ctor_NegativeWidth) {
	rectangle rect(1, 1, -1, 1);
	ASSERT_TRUE(!rect);
	fails += ::testing::Test::HasFailure();
}

// Parametized constructor will create a rectangle and verify if it is sized: 
// "Width and height are always positive integers" - from Purpose file
TEST_F(Tester, Ctor_NegativeX) {
	rectangle rect(-10, 10, 10, 10);
	ASSERT_FALSE(!rect);
	fails += ::testing::Test::HasFailure();
}

// Parametized constructor will create a rectangle and verify if it is sized: 
// "Width and height are always positive integers" - from Purpose file
TEST_F(Tester, Ctor_NegativeY) {
	rectangle rect(10, -10, 10, 10);
	ASSERT_FALSE(!rect);
	fails += ::testing::Test::HasFailure();
}

// Parametized constructor will create a rectangle and verify if it is sized: 
// "Width and height are always positive integers" - from Purpose file
TEST_F(Tester, Ctor_NoHeight) {
	rectangle rect(10, 10, 10, 0);
	ASSERT_TRUE(!rect);
	fails += ::testing::Test::HasFailure();
}

// Default contructor will create a invalid rectangle
TEST_F(Tester, Ctor_NoParams) {
	rectangle rect;
	ASSERT_TRUE(!rect);
	fails += ::testing::Test::HasFailure();
}
// Parametized constructor will create a rectangle and verify if it is sized: 
// "Width and height are always positive integers" - from Purpose file
TEST_F(Tester, Ctor_NoWidth) {
	rectangle rect(1, 1, 0, 1);
	ASSERT_TRUE(!rect);
	fails += ::testing::Test::HasFailure();
}

// Parametized constructor will create a rectangle and verify if it is sized: 
// "Width and height are always positive integers" - from Purpose file
TEST_F(Tester, Ctor_OK) {
	rectangle rect(1, 1, 1, 1);
	ASSERT_FALSE(!rect);
	fails += ::testing::Test::HasFailure();
}

// Equal operator
TEST_F(Tester, EqualOptor_InvalidVsInvalidTrue) {
	rectangle invalid_a;
	rectangle invalid_b;

	ASSERT_TRUE(invalid_a == invalid_b);
	fails += ::testing::Test::HasFailure();
}

// Equal operator
TEST_F(Tester, EqualOptor_InvalidVsValidFalse) {
	rectangle invalid;
	rectangle valid(1, 1, 1, 1);

	ASSERT_FALSE(invalid == valid);
	fails += ::testing::Test::HasFailure();
}

// Equal operator
TEST_F(Tester, EqualOptor_ValidVsValidFalse) {
	rectangle valid_a(0, 0, 1, 1);
	rectangle valid_b(1, 1, 1, 1);

	ASSERT_FALSE(valid_a == valid_b);
	fails += ::testing::Test::HasFailure();
}

// Equal operator
TEST_F(Tester, EqualOptor_ValidVsValidTrue) {
	rectangle valid_a(1, 1, 1, 1);
	rectangle valid_b(1, 1, 1, 1);

	ASSERT_TRUE(valid_a == valid_b);
	fails += ::testing::Test::HasFailure();
}

// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST_F(Tester, GetIntersection_False) {
	rectangle rect1(0, 0, 2, 2);
	rectangle rect2(2, 0, 2, 2);

	// get_intersection return a shared_ptr to an invalid rectangle
	ASSERT_TRUE(!(*rect1.get_intersection(rect2)));
	fails += ::testing::Test::HasFailure();
}

// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST_F(Tester, GetIntersection_FalseLimitX) {
	rectangle rect1(0, 0, 2, 2);
	rectangle rect2(2, 0, 2, 2);

	// get_intersection return a shared_ptr to an invalid rectangle
	ASSERT_TRUE(!(*rect1.get_intersection(rect2)));
	fails += ::testing::Test::HasFailure();
}

// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST_F(Tester, GetIntersection_FalseLimitY) {
	rectangle rect1(0, 0, 2, 2);
	rectangle rect2(0, 2, 2, 2);

	// get_intersection return a shared_ptr to an invalid rectangle
	ASSERT_TRUE(!(*rect1.get_intersection(rect2)));
	fails += ::testing::Test::HasFailure();
}

// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST_F(Tester, GetIntersection_True) {
	rectangle rect1(0, 0, 2, 2);
	rectangle rect2(1, 1, 2, 2);

	// get_intersection return a shared_ptr to a valid rectangle
	ASSERT_FALSE(!(*rect1.get_intersection(rect2)));
	fails += ::testing::Test::HasFailure();
}
// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST_F(Tester, GetIntersection_TrueLimitX) {
	rectangle rect1(0, 0, 2, 2);
	rectangle rect2(0, 1, 2, 2);
	
	// get_intersection return a shared_ptr to a valid rectangle
	ASSERT_FALSE(!(*rect1.get_intersection(rect2)));
	fails += ::testing::Test::HasFailure();
}
// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST_F(Tester, GetIntersection_TrueLimitY) {
	rectangle rect1(0, 0, 2, 2);
	rectangle rect2(1, 0, 2, 2);

	// get_intersection return a shared_ptr to a valid rectangle
	ASSERT_FALSE(!(*rect1.get_intersection(rect2)));
	fails += ::testing::Test::HasFailure();
}
// Used to create an valid intersection rectangle between 
// this and another rectangle
TEST_F(Tester, GetIntersection_TrueVerified) {
	rectangle rect1(0, 0, 2, 2);
	rectangle rect2(1, 1, 2, 2);

	// The rectangle returned by get_intersection should have this values
	ASSERT_STREQ((*rect1.get_intersection(rect2)).to_string().c_str(), "(1, 1), w=1, h=1");
	fails += ::testing::Test::HasFailure();
}
// Used to verify if exist a valid intersection rectangle
// between this and another rectangle.
TEST_F(Tester, Intersction_False) {
	rectangle rect1(1, 0, 1, 1);
	rectangle rect2(0, 0, 1, 1);

	ASSERT_FALSE(rect1.intersect(rect2));
	fails += ::testing::Test::HasFailure();
}
// Used to verify if exist a valid intersection rectangle
// between this and another rectangle.
TEST_F(Tester, Intersction_True) {
	rectangle rect1(1, 1, 2, 2);
	rectangle rect2(0, 0, 2, 2);

	ASSERT_TRUE(rect1.intersect(rect2));
	fails += ::testing::Test::HasFailure();
}
// Operator << to make it easy to print the values
TEST_F(Tester, OstreamOperator_1) {
	rectangles_matches matches;
	rectangle rect(3, 1, 2, 2);

	matches.add_rectangle(rect);
	ASSERT_STREQ(matches.to_string().c_str(), "Input:\n"
		                                      "\t1: Rectangle at (3, 1), w=2, h=2.\n");
	fails += ::testing::Test::HasFailure();
}

// Operator << to make it easy to print the values
TEST_F(Tester, OstreamOperator_2) {
	rectangles_matches matches;
	rectangle rect1(3, 1, 2, 2);
	rectangle rect2(1, 1, 2, 2);

	matches.add_rectangle(rect1);
	matches.add_rectangle(rect2);
	ASSERT_STREQ(matches.to_string().c_str(), "Input:\n"
	                                          "\t1: Rectangle at (3, 1), w=2, h=2.\n"
	                                          "\t2: Rectangle at (1, 1), w=2, h=2.\n");

	fails += ::testing::Test::HasFailure();
}

// Operator << to make it easy to print the values
TEST_F(Tester, OstreamOperator_3) {
	rectangles_matches matches;
	rectangle rect1(3, 1, 2, 2);
	rectangle rect2(1, 1, 2, 2);
	rectangle rect3(0, 0, 2, 2);

	matches.add_rectangle(rect1);
	matches.add_rectangle(rect2);
	matches.add_rectangle(rect3);
	ASSERT_STREQ(matches.to_string().c_str(), "Input:\n"
	                                          "\t1: Rectangle at (3, 1), w=2, h=2.\n"
	                                          "\t2: Rectangle at (1, 1), w=2, h=2.\n"
	                                          "\t3: Rectangle at (0, 0), w=2, h=2.\n\n"
	                                          "Intersections\n"
	                                          "\tBetween rectangle 2 and 3 at (1, 1), w=1, h=1.\n");
	fails += ::testing::Test::HasFailure();
}

// Operator << to make it easy to print the values
TEST_F(Tester, OstreamOptor_NegativeHeight) {
	rectangle rect(1, 1, 1, -1);
	ASSERT_STREQ(rect.to_string().c_str(), "(1, 1), w=1, h=-1");
	fails += ::testing::Test::HasFailure();
}

// Operator << to make it easy to print the values
TEST_F(Tester, OstreamOptor_NegaviteWidht) {
	rectangle rect(1, 1, -1, 1);
	ASSERT_STREQ(rect.to_string().c_str(), "(1, 1), w=-1, h=1");
	fails += ::testing::Test::HasFailure();
}

// Operator << to make it easy to print the values
TEST_F(Tester, OstreamOptor_NegativeX) {
	rectangle rect(-1, 1, 1, 1);
	ASSERT_STREQ(rect.to_string().c_str(), "(-1, 1), w=1, h=1");
	fails += ::testing::Test::HasFailure();
}

// Operator << to make it easy to print the values
TEST_F(Tester, OstreamOptor_NegativeY) {
	rectangle rect(1, -1, 1, 1);
	ASSERT_STREQ(rect.to_string().c_str(), "(1, -1), w=1, h=1");
	fails += ::testing::Test::HasFailure();
}

// Operator << to make it easy to print the values
TEST_F(Tester, OstreamOptor_NoHeight) {
	rectangle rect(1, 1, 1, 0);
	ASSERT_STREQ(rect.to_string().c_str(), "(1, 1), w=1, h=0");
	fails += ::testing::Test::HasFailure();
}

// Operator << to make it easy to print the values
TEST_F(Tester, OstreamOptor_NoValues) {
	rectangle rect;
	ASSERT_STREQ(rect.to_string().c_str(), "(0, 0), w=0, h=0");
	fails += ::testing::Test::HasFailure();
}

// Operator << to make it easy to print the values
TEST_F(Tester, OstreamOptor_NoWidht) {
	rectangle rect(1, 1, 0, 1);
	ASSERT_STREQ(rect.to_string().c_str(), "(1, 1), w=0, h=1");
	fails += ::testing::Test::HasFailure();
}

// Operator << to make it easy to print the values
TEST_F(Tester, OstreamOptor_Ok) {
	rectangle rect(1, 1, 1, 1);
	ASSERT_STREQ(rect.to_string().c_str(), "(1, 1), w=1, h=1");
	fails += ::testing::Test::HasFailure();
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
