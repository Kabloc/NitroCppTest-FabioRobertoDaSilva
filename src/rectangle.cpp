#include <rectangle.h>

// Parametized constructor will create a rectangle and verify if
// it is sized: 
// "Width and height are always positive integers" - from Purpose file
rectangle::rectangle(int x, int y, unsigned int w, unsigned int h) 
	: top_left_{ y, x }
	, bottom_rigth_{ y + h, x + w } {

	// If it is zero sized, it will be invalidated
	valid_ = !(!w || !h);
}

// Useful to verify if it is valid
rectangle::operator bool() const { 
	return valid_; 
}

// Equal operator
bool rectangle::operator==(const rectangle& another) const {
	return ((valid_        == another.valid_) &&
	        (top_left_     == another.top_left_) &&
	        (bottom_rigth_ == another.bottom_rigth_));
}

// Operator << to make it easy to print the values
std::ostream& operator<<(std::ostream& output, const rectangle& rect) {
	// Example from purpose file:
	// (top, left), w=(left - right), h=(bottom - top)
		output << "(" << rect.top_left_.second << ", " << rect.top_left_.first << "), "
		       << "w=" << rect.bottom_rigth_.second - rect.top_left_.second << ", "
		       << "h=" << rect.bottom_rigth_.first - rect.top_left_.first;

	return output;
}

// Used to print the intersections as purposed
const std::string rectangle::to_string() const {
	std::stringstream ss;
	ss << (*this);
	return ss.str();
}

// Used to verify if exist a valid intersection rectangle
// between this and another rectangle.
bool rectangle::intersect(const rectangle& another) const {
	// Verifying if this and the other rectangle is a valid
	if ((!valid_) || (!another)) 
		return false;

	// If there are the same values
	if ((*this) == another)
		return true;

	// Verifying if the other rectangle is under or above me
	if ((top_left_.first >= another.bottom_rigth_.first) ||
		(another.top_left_.first >= bottom_rigth_.first))
		return false;

	// Verifying if the other rectangle is left or right of me 
	if ((top_left_.second >= another.bottom_rigth_.second) ||
		(another.top_left_.second >= bottom_rigth_.second))
		return false;

	return true;
}

// Used to create an valid intersection rectangle between 
// this and another rectangle
const rectangle rectangle::get_intersection(const rectangle& another) const {
	rectangle result;

	// If there are the same values
	if ((*this) == another) {
		result = another;
		return result;
	}

	// Verifying if exist a valid intersection.
	if (intersect(another)) {
		int x = { 0 }, y = { 0 };

		// Getting top
		x = std::max(top_left_.first, another.top_left_.first);

		// Getting left
		y = std::max(top_left_.second, another.top_left_.second);

		// Saving top_left_;
		result.top_left_ = std::make_pair(x, y);

		// Getting bottom
		x = std::min(bottom_rigth_.first, another.bottom_rigth_.first);

		// Getting right
		y = std::min(bottom_rigth_.second, another.bottom_rigth_.second);

		// Saving bottom_right
		result.bottom_rigth_ = std::make_pair(x, y);

		// There I can validate the rectangle because
		// all data come from valid rectangles
		result.valid_ = true;
	}

	return result;
}

// Assignment operator 
rectangle& rectangle::operator=(const rectangle& another) {
	valid_ = another.valid_;
	top_left_ = another.top_left_;
	bottom_rigth_ = another.bottom_rigth_;
	return *this;
}