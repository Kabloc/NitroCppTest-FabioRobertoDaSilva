#include <rectangle.h>

// Parametized constructor will create a rectangle and verify if
// it is sized: 
// "Width and height are always positive integers" - from Purpose file
rectangle::rectangle(int x, int y, int w, int h) 
	: vertices_{ y, x, y + h, x + w } {

	// If it is of zero or negative size, it will be invalidated.
	valid_ = !((w <= 0) || (h <= 0));
}

// Useful to verify if it is valid
rectangle::operator bool() const { 
	return valid_; 
}

// Equal operator
bool rectangle::operator==(const rectangle& another) const {
	return ((valid_        == another.valid_) &&
	        (vertices_     == another.vertices_));
}

// Operator << to make it easy to print the values
std::ostream& operator<<(std::ostream& output, const rectangle& rect) {
	// Example from purpose file:
	// (left, top), w=(right - left), h=(bottom - top)
		output << "(" << rect.vertices_[rectangle::Left] << ", " << rect.vertices_[rectangle::Top] << "), "
		       << "w=" << rect.vertices_[rectangle::Right] - rect.vertices_[rectangle::Left] << ", "
		       << "h=" << rect.vertices_[rectangle::Bottom] - rect.vertices_[rectangle::Top];

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
	if ((vertices_[Top] >= another.vertices_[Bottom]) ||
		(another.vertices_[Top] >= vertices_[Bottom]))
		return false;

	// Verifying if the other rectangle is left or right of me 
	if ((vertices_[Left] >= another.vertices_[Right]) ||
		(another.vertices_[Left] >= vertices_[Right]))
		return false;

	return true;
}

// Used to create an valid intersection rectangle between this and another rectangle
rectangle::ptr_t rectangle::get_intersection(const rectangle& another) const {
	auto result = std::make_shared<rectangle>();

	// If any involved rectangle is not valid, do nothing
	if ((!valid_) || (!another))
		return result;

	// If there are the same values
	if ((*this) == another) {
		(*result) = another;
		return result;
	}

	// Verifying if exist a valid intersection.
	if (intersect(another)) {
		result->vertices_ = {
			// Getting top
			std::max(vertices_[Top], another.vertices_[Top]),

			// Getting left
			std::max(vertices_[Left], another.vertices_[Left]),

			// Getting bottom
			std::min(vertices_[Bottom], another.vertices_[Bottom]),

			// Getting right
			std::min(vertices_[Right], another.vertices_[Right])
		};

		// There I can validate the rectangle because
		// all data come from valid rectangles
		result->valid_ = true;
	}

	return result;
}

// Assignment operator 
rectangle& rectangle::operator=(const rectangle& another) {
	valid_ = another.valid_;
	vertices_ = another.vertices_;
	return *this;
}