#include <iostream>
#include <algorithm>
#include <memory>
#include <utility>
#include <sstream>
#include <vector>
#include "json.hpp"

// As purposed: "The JSON file may contain any number of input rectangles. 
// Your program must be able to process JSON files containing at least 10 
// rectangles. You may discard the remaining rectangles 
// after the first 10." - from Purpose file
#define MIN_RECT 10
#define MAX_RECT 10

class rectangle {
public:
	// Shared pointer, it will be useful to manage de memory
	using ptr_t = std::shared_ptr<rectangle>;

	// Default contructor will create a invalid rectangle
	rectangle() { }

	// Parametized constructor will create a rectangle and verify if
	// it is sized: 
	// "Width and height are always positive integers" - from Purpose file
	rectangle(int x, int y, unsigned int w, unsigned int h) 
		: top_left_{ y, x }
		, bottom_rigth_{ y + h, x + w } {

		// If it is zero sized, it will be invalidated
		valid_ = !(!w || !h);
	}

	// Useful to verify if it is valid
	explicit operator bool() const { return valid_; }

	// Equal operator
	bool operator==(const rectangle& another) const {
		return ((valid_        == another.valid_) &&
		        (top_left_     == another.top_left_) &&
		        (bottom_rigth_ == another.bottom_rigth_));
	}

	// Assignment operator 
	rectangle& operator=(const rectangle& another) {
		valid_ = another.valid_;
		top_left_ = another.top_left_;
		bottom_rigth_ = another.bottom_rigth_;
		return *this;
	}

	// Destructor just invalidate the object
	~rectangle() { valid_ = false; }

	// Operator & to verify if have an intersection
	friend bool operator&(const rectangle& lRect, const rectangle& rRect) {
		return lRect.intersect(rRect);
	}

	// Operator && to create the intersection rectangle
	friend ptr_t operator&&(const rectangle& lRect, const rectangle& rRect) {
		return lRect.get_intersection(rRect);
	}

	// Operator << to make it easy to print the values
	friend std::ostream& operator<<(std::ostream& output, const rectangle& rect) {
		// Example from purpose file:
		// (top, left), w=(left - right), h=(bottom - top)
		if (!rect)
			output << "(?, ?), w=?, h=?";
		else
			output << "(" << rect.top_left_.second << ", " << rect.top_left_.first << "), "
			       << "w=" << rect.bottom_rigth_.second - rect.top_left_.second << ", "
			       << "h=" << rect.bottom_rigth_.first - rect.top_left_.first;

		return output;
	}

private:
	// Used to verify if exist a valid intersection rectangle
	// between this and another rectangle.
	bool intersect(const rectangle& another) const {
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
	ptr_t get_intersection(const rectangle& another) const {
		auto result = std::make_shared<rectangle>();

		// If there are the same values
		if ((*this) == another) {
		    (*result) = another;
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
			(*result).top_left_ = std::make_pair(x, y);

			// Getting bottom
			x = std::min(bottom_rigth_.first, another.bottom_rigth_.first);

			// Getting right
			y = std::min(bottom_rigth_.second, another.bottom_rigth_.second);

			// Saving bottom_right
			(*result).bottom_rigth_ = std::make_pair(x, y);

			// There I can validate the rectangle because
			// all data come from valid rectangles
			(*result).valid_ = true;
		}

		return result;
	}

	// I prefer to save the (Top, Left) point and (Bottom, Right) point 
	// to make easy to make the calculus 
	bool valid_ = { false };
	std::pair<int, int> top_left_ = { 0, 0 };
	std::pair<int, int> bottom_rigth_ = { 0, 0 };
};

class rectangles_mactches {
public:
	// Just add a rectangle
	void add_rectangle(rectangle::ptr_t new_rect) {
		rectangles_.push_back(new_rect);
	}

	// Used to print the intersections as purposed
	void print_intersections() {
		// Build the intersection tree
		build_intersections();

		// Start the print as purposed:
		// Input:
		//		[N of rectangle]: Rectangle at ([up], [left]), w = [width], h = [height].
		std::cout << "Input:" << std::endl;
		for (size_t idx = { 0 }; idx < rectangles_.size(); idx++) {
			std::cout << '\t' << idx + 1 << ": Rectangle at " << (*rectangles_[idx]) << "." << std::endl;
		}

		// Continue the print as purposed
		//Intersections
		//		Between rectangle [list of parents] at ([up], [left]), w = [width], h = [height].
		std::cout << std::endl << "Intersections" << std::endl;
		for (const auto &intersection : intersections_) {
			std::cout << '\t' << "Between rectangle ";
			for (size_t idx = { 0 }; idx < intersection.parents.size(); idx++) {
				// if is not last just print it
				if (idx < intersection.parents.size() - 1) {
					std::cout << intersection.parents[idx] + 1;
					// after the penultimate member has no comma
					if (idx < intersection.parents.size() - 2)
						std::cout << ", ";
				}
				else
					// the last member
					std::cout << " and " << intersection.parents[idx] + 1;
			}
			// rectangle's values
			std::cout << " at " << (*intersection.rect) << "." << std::endl;
		}
	}
private:
	// Clean the intersection tree and create a new
	void build_intersections() {
		// Start with low level
		int level = { 0 };
		// Clean the old tree
		intersections_.clear();
		// Get all parents level after level
		while (build_intersections(level++));
	}

	bool build_intersections(unsigned int level) {
		// Zero is the first level
		if (!level) {
			// Make a permutation between the rectangles:
			// Example: {1, 2, 3, 4}
			//		1 & 2, 1 & 3, 1 & 4
			//		2 & 3, 2 & 4
			//		3 & 4

			// As purposed: "Rectangle A&B is the same as B&A and should
			// result in only one rectangle in the result." - from Purpose file	
			for (size_t idxA = { 0 }; idxA < rectangles_.size(); idxA++) {
				for (size_t idxB = { idxA + 1 }; idxB < rectangles_.size(); idxB++) {
					if ((*rectangles_[idxA]) & (*rectangles_[idxB])) {
						interaction_item item((*rectangles_[idxA]) && (*rectangles_[idxB]));
						item.parents.push_back(idxA);
						item.parents.push_back(idxB);
						intersections_.push_back(item);
					}
				}
			}
			// Level's end
			return true;
		} else {
			// All the others levels
			std::vector<interaction_item> news_intersections;
			// Make a permutation between the rectangles and the intersections rectangles
			// Example: {1, 2, 3, 4} and {1&3, 1&4, 2&3, 2&4, 3&4 }
			//		1 & 1&3, 1 & 1&4, ..., 1 & 3&4
			//		2 & 1&3, 2 & 1&4, ..., 2 & 3&4
			//      ...
			//		4 & 1&3, 4 & 1&4, ..., 4 & 3&4

			for (size_t idx = { 0 }; idx < rectangles_.size(); idx++) {
				for (const auto &item : intersections_) {

					// The number of parents determine the level
					if (item.parents.size() < level + 1)
						continue;
					
					// But "1 & 1&3" and "1 & 1&4" is a ilegal permutation because will always return true
					// because A&B is the same B&A and A's children will intersect with A 
					if (std::find(item.parents.begin(), item.parents.end(), idx) != item.parents.end())
						continue;

					// Verify if exist a valid intersecting rectangle 
					if ((*item.rect) & (*rectangles_[idx])) {

						// Before calculating the intersection rectangle, make sure that this combination already exists
						auto new_parents = item.parents;
						new_parents.push_back(idx);
						std::sort(new_parents.begin(), new_parents.end());
						bool found = { false };
						for (const auto &verify_item : news_intersections) {
							if (std::equal(new_parents.begin(), new_parents.end(), verify_item.parents.begin())) {
								found = true;
								break;
							}
						}

						// If so, do not need to do this calculation.
						if (found)
							continue;

						interaction_item new_item((*item.rect) && (*rectangles_[idx]));
						new_item.parents = new_parents;
						news_intersections.push_back(new_item);
					}
				}
			}
			// If this level generated new intersecting rectangles
			if (news_intersections.size()) {
				// Add to intersection list
				intersections_.insert(intersections_.end(), news_intersections.begin(), news_intersections.end());
				// Level's end
				return true;
			}
		}
		// There're no new intersecting rectangles
		return false;
	}

	// Intersection tree node
	struct interaction_item {
		interaction_item(rectangle::ptr_t r_) : rect(r_) {}
		rectangle::ptr_t rect;
		std::vector<int> parents;
	};

	// Inputted rectangles
	std::vector<rectangle::ptr_t > rectangles_;

	// Intersecting rectangles' tree
	std::vector<interaction_item> intersections_;

};

int main(int argc, char* argv[]) {

	std::string json_buffer;
	std::cerr << "If nothing happens press [Ctrl+C]. Usage: app < rects.json";
	while (std::cin.good()) {
		std::string line;
		std::getline(std::cin, line);
		json_buffer += line;
	}
	std::cerr << "\r                                                          \r";

	try {
		rectangles_mactches rect_macthes;
		auto json = nlohmann::json::parse(json_buffer);

		// As purposed: "The JSON file may contain any number of input rectangles. 
		// Your program must be able to process JSON files containing at least 10 
		// rectangles." - from Purpose file.
		if (json["rects"].size() < MIN_RECT) {
			std::cerr << "At least " << MIN_RECT << " rectangles." << std::endl;
			return -1;
		}
		auto begin = json["rects"].begin();
		auto end = json["rects"].end();

		//As purposed: " You may discard the remaining rectangles 
		// after the first 10." - from Purpose file
		if (json["rects"].size() > MAX_RECT)
			end = json["rects"].begin() + MAX_RECT;

		// Iterating the rects and adding to rect_matches
		for (auto j_rect = begin; j_rect < end; j_rect++) {
			rect_macthes.add_rectangle(std::make_shared<rectangle>(
				(*j_rect)["x"], (*j_rect)["y"], (*j_rect)["w"], (*j_rect)["h"]));
		}

		// Where everthing happen...
		rect_macthes.print_intersections();

		return 0;
	} catch (nlohmann::json::parse_error& e) {
		std::cerr << "message: " << e.what() << '\n'
			<< "exception id: " << e.id << '\n'
			<< "byte position of error: " << e.byte << std::endl;
	}
	return -1;
}