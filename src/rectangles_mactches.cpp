#include <rectangles_mactches.h>

// Just add a rectangle
void rectangles_mactches::add_rectangle(rectangle::ptr_t new_rect) {
	rectangles_.push_back(new_rect);
}

// Used to print the intersections as purposed
void rectangles_mactches::print_intersections() {
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

// Clean the intersection tree and create a new
void rectangles_mactches::build_intersections() {
	// Start with low level
	int level = { 0 };
	// Clean the old tree
	intersections_.clear();
	// Get all parents level after level
	while (build_intersections(level++));
}

bool rectangles_mactches::build_intersections(unsigned int level) {
	// Zero is the first level
	if (!level) {
		// Make a permutation between the rectangles:
		// Example: {1, 2, 3, 4}
		//      1 & 2, 1 & 3, 1 & 4
		//      2 & 3, 2 & 4
		//      3 & 4

		// As purposed: "Rectangle A&B is the same as B&A and should
		// result in only one rectangle in the result." - from Purpose file	
		for (size_t idxA = { 0 }; idxA < rectangles_.size(); idxA++) {
			for (size_t idxB = { idxA + 1 }; idxB < rectangles_.size(); idxB++) {
				if ((*rectangles_[idxA]).intersect(*rectangles_[idxB])) {
					interaction_item item((*rectangles_[idxA]).get_intersection(*rectangles_[idxB]));
					item.parents.push_back(idxA);
					item.parents.push_back(idxB);
					intersections_.push_back(item);
				}
			}
		}
		// Level's end
		return (intersections_.size() > 0);
	} else {
		// All the others levels
		std::vector<interaction_item> news_intersections;
		// Make a permutation between the rectangles and the intersections rectangles
		// Example: {1, 2, 3, 4} and {1&3, 1&4, 2&3, 2&4, 3&4 }
		//      1 & 1&3, 1 & 1&4, ..., 1 & 3&4
		//      2 & 1&3, 2 & 1&4, ..., 2 & 3&4
		//      ...
		//      4 & 1&3, 4 & 1&4, ..., 4 & 3&4

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
				if ((*item.rect).intersect(*rectangles_[idx])) {

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

					interaction_item new_item((*item.rect).get_intersection(*rectangles_[idx]));
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