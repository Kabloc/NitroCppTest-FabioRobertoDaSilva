#pragma once
#ifndef _RECTANGLES_MATCHES_H_
#define _RECTANGLES_MATCHES_H_
#include <rectangle.h>

class rectangles_matches {
public:
	// Add a rectangle and update the tree
	bool add_rectangle(const rectangle& new_rect);

	// Operator << to make it easy to print the values
	friend std::ostream& operator<<(std::ostream& output, const rectangles_matches& rect);

	// Used to print the intersections as purposed
	const std::string to_string() const ;

private:
	// Intersection tree node
	class interaction_node {
		friend class rectangles_matches;
		friend std::ostream& operator<<(std::ostream& output, const rectangles_matches& rect);

		interaction_node(rectangle::ptr_t r_) : rect(r_) {}

		// Rectangle's size and location
		rectangle::ptr_t rect;

		// List of rectangles' id that compose this rectangle
		std::vector<int> parents;
	};

	// Each node will have an ID to future search|delete functions
	int actual_id_ = { 0 };

	// Intersecting rectangles' tree level
	using intersection_level_t = std::vector<interaction_node>;

	// Intersection rectangles' tree
	std::vector<intersection_level_t> intersection_tree_;

};
#endif //_RECTANGLES_MACTCHES_H_
