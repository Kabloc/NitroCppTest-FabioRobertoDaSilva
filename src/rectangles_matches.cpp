#include <rectangles_matches.h>

// Just add a rectangle
bool rectangles_matches::add_rectangle(const rectangle& new_rect) {

	auto new_rect_ptr = std::make_shared<rectangle>(new_rect);

	// if it is an invalid shared_ptr or an invalid rectangle, do nothing
	if ((!new_rect_ptr) || !(*new_rect_ptr))
		return false;

	// Creating a new node for the tree
	int new_rect_id = ++actual_id_;
	interaction_node new_node(new_rect_ptr);
	new_node.parents.push_back(new_rect_id);

	// If it is the first node
	if (intersection_tree_.size() == 0) {
		// Create a new level with one node
		intersection_tree_.push_back(intersection_level_t({ new_node }));
		return true;
	}

	if (intersection_tree_[0].size()) {
		bool had_new_intersection = { false };
		size_t level = { 0 };
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
				if (!node.rect->intersect(*new_rect_ptr))
					continue;

				// But "1 & 1&3" and "1 & 1&4" is a ilegal permutation because will always return true
				// because A&B is the same B&A and A's children will intersect with A 
				if (std::find(node.parents.begin(), node.parents.end(), new_rect_id) != node.parents.end())
					continue;

				// Create a new intersection item to next level
				interaction_node new_node(std::make_shared<rectangle>(node.rect->get_intersection(*new_rect_ptr)));
				new_node.parents = node.parents;
				new_node.parents.push_back(new_rect_id);

				// Verify if exist next level
				if (intersection_tree_.size() == level + 1) {
					// Create a new level with one node
					intersection_tree_.push_back(intersection_level_t({ new_node }));
				}
				else {
					// TODO: Insert in order instead of sort after insert
					intersection_tree_[level + 1].push_back(new_node);

					// Keeping the ids list sorted
					std::sort(intersection_tree_[level + 1].begin(), intersection_tree_[level + 1].end(),
						[](interaction_node a, interaction_node b) {
						return a.parents < b.parents;
					}
					);
				}
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
	return true;
}

// Operator << to make it easy to print the values
std::ostream& operator<<(std::ostream& output, const rectangles_matches& rect) {

	for (size_t level = { 0 }; level < rect.intersection_tree_.size(); level++) {
		if (level == 0) { // The first level is the imputed rectangles
		                  // Start the print as purposed:
		                  // Input:
		                  //    [rectangle number]: Rectangle at ([up], [left]), w = [width], h = [height].
			output << "Input:" << std::endl;
			for (const auto &node : rect.intersection_tree_[level]) {
				// REVIEWER NOTE: "rectangle number" today is the internal ID but can be the position
				output << '\t' << node.parents[0] << ": Rectangle at " << (*node.rect) << "." << std::endl;
			}
		}
		else { // The others levels are the intersections
		       // Continue the print as purposed
		       // Intersections
		       //    Between rectangle [list of parents] at ([up], [left]), w = [width], h = [height].
			if (level == 1)
				output << std::endl << "Intersections" << std::endl;
			for (const auto &node : rect.intersection_tree_[level]) {
				output << '\t' << "Between rectangle ";
				for (size_t idx = { 0 }; idx < node.parents.size(); idx++) {
					// if is not last just print it
					if (idx < node.parents.size() - 1) {
						output << node.parents[idx];
						// after the penultimate member has no comma
						if (idx < node.parents.size() - 2)
							output << ", ";
					}
					else
						// the last member
						output << " and " << node.parents[idx];
				}
				// rectangle's values
				output << " at " << (*node.rect) << "." << std::endl;
			}
		}
	}
	return output;
}

// Used to print the intersections as purposed
const std::string rectangles_matches::to_string() const {
	std::stringstream ss;
	ss << (*this);
	return ss.str();
}

