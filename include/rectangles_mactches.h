#pragma once
#ifndef _RECTANGLES_MACTCHES_H_
#define _RECTANGLES_MACTCHES_H_
#include <rectangle.h>

class rectangles_mactches {
public:
	// Just add a rectangle
	void add_rectangle(rectangle::ptr_t new_rect);

	// Used to print the intersections as purposed
	void print_intersections();

private:
	// Clean the intersection tree and create a new
	void build_intersections();

	bool build_intersections(unsigned int level);

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
#endif //_RECTANGLES_MACTCHES_H_
