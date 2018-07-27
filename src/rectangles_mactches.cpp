#include <rectangles_mactches.h>

// Just add a rectangle
void rectangles_mactches::add_rectangle(rectangle::ptr_t new_rect) {

	// Creating a new node for the tree
	int new_rect_id = intersection_tree_[0].size() + 1;
	interaction_node new_node(new_rect);
	new_node.parents.push_back(new_rect_id);

	if (intersection_tree_[0].size()) {
		bool had_new_intersection = { false };
		int level = { 0 };
		// Make a permutation between the rectangles:
		// Example: {1, 2, 3, 4}
		//      1 & 2, 1 & 3, 1 & 4
		//      2 & 3, 2 & 4
		//      3 & 4

		// As purposed: "Rectangle A&B is the same as B&A and should
		// result in only one rectangle in the result." - from Purpose file	
		do {
			had_new_intersection = false;
			// Make a permutation between the rectangles and the intersections rectangles
			// Example: {1, 2, 3, 4} and {1&3, 1&4, 2&3, 2&4, 3&4 }
			//      1 & 1&3, 1 & 1&4, ..., 1 & 3&4
			//      2 & 1&3, 2 & 1&4, ..., 2 & 3&4
			//      ...
			//      4 & 1&3, 4 & 1&4, ..., 4 & 3&4
			for (const auto& node : intersection_tree_[level]) {

				// There's intersection?
				if (!node.rect->intersect(*new_rect))
					continue;

				// But "1 & 1&3" and "1 & 1&4" is a ilegal permutation because will always return true
				// because A&B is the same B&A and A's children will intersect with A 
				if (std::find(node.parents.begin(), node.parents.end(), new_rect_id) != node.parents.end())
					continue;

				// Create a new intersection item to next level
				interaction_node new_item(node.rect->get_intersection(*new_rect));
				new_item.parents = node.parents;
				new_item.parents.push_back(new_rect_id);
				intersection_tree_[level + 1].push_back(new_item);

				// Keeping the ids list sorted
				std::sort(intersection_tree_[level + 1].begin(), intersection_tree_[level + 1].end(), 
					[](interaction_node a, interaction_node b) {
						return a.parents < b.parents;
					}
				);
				had_new_intersection = true;
			}
			// If there was no intersection at the current level 
			// it will be impossible to have the next level
			if (!had_new_intersection)
				break;
			level++;
		} while (1);
	}
	// All inserted rectangle must be in the first level
	intersection_tree_[0].push_back(new_node);
}

// Used to print the intersections as purposed
void rectangles_mactches::print_intersections() {

	for (const auto &level : intersection_tree_ ) {
		// level.first: the actual level
		// level.second: list of level's nodes
		if (level.first == 0) { // The first level is the imputed rectangles
			// Start the print as purposed:
			// Input:
			//		[N of rectangle]: Rectangle at ([up], [left]), w = [width], h = [height].
			std::cout << "Input:" << std::endl;
			for (const auto &node : level.second) {
				std::cout << '\t' << node.parents[0] << ": Rectangle at " << (*node.rect) << "." << std::endl;
			}
		} else { // The others levels are the intersections
			// Continue the print as purposed
			// Intersections
			//		Between rectangle [list of parents] at ([up], [left]), w = [width], h = [height].
			if (level.first == 1)
				std::cout << std::endl << "Intersections" << std::endl;
			for (const auto &node : level.second) {
				std::cout << '\t' << "Between rectangle ";
				for (size_t idx = { 0 }; idx < node.parents.size(); idx++) {
					// if is not last just print it
					if (idx < node.parents.size() - 1) {
						std::cout << node.parents[idx];
						// after the penultimate member has no comma
						if (idx < node.parents.size() - 2)
							std::cout << ", ";
					}
					else
						// the last member
						std::cout << " and " << node.parents[idx];
				}
				// rectangle's values
				std::cout << " at " << (*node.rect) << "." << std::endl;
			}
		}
	}
}
