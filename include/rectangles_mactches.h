#pragma once
#ifndef _RECTANGLES_MACTCHES_H_
#define _RECTANGLES_MACTCHES_H_
#include <map>
#include <rectangle.h>

class rectangles_mactches {
public:
	// Just add a rectangle
	void add_rectangle(rectangle::ptr_t new_rect);

	// Used to print the intersections as purposed
	void print_intersections();

private:
	// Intersection tree node
	struct interaction_node {
		interaction_node(rectangle::ptr_t r_) : rect(r_) {}

		// Rectangle's size and location
		rectangle::ptr_t rect;

		// List of rectangles' id that compose this rectangle
		std::vector<int> parents;
	};

	// Intersecting rectangles' tree level
	using intersection_level_t = std::vector<interaction_node>;

	// Intersection rectangles' tree
	std::map<int, intersection_level_t> intersection_tree_;

};
#endif //_RECTANGLES_MACTCHES_H_
