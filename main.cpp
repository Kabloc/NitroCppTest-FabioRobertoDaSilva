#include <iostream>
#include <algorithm>
#include <memory>
#include <utility>
#include <sstream>
#include <vector>

class rectangle {
public:
	using ptr_t = std::shared_ptr<rectangle>;

	rectangle() { }

	rectangle(int x, int y, unsigned int w, unsigned int h) 
		: top_left_{ y, x }
		, bottom_rigth_{ y + h, x + w } {

		// If it is zero sized, it will be invalidated
		valid_ = !(!w || !h);
	}

	explicit operator bool() const { return valid_; }

	~rectangle() { valid_ = false; }

	friend bool operator&(const rectangle& lRect, const rectangle& rRect) {
		return lRect.intersect(rRect);
	}

	friend ptr_t operator&&(const rectangle& lRect, const rectangle& rRect) {
		return lRect.get_intersection(rRect);
	}

	friend std::ostream& operator<<(std::ostream& output, const rectangle& rect) {
		// (top, left), w=left-right, h=bottom-top
		if (!rect)
			output << "at (?, ?), w=?, h=?";
		else
			output << "at (" << rect.top_left_.second << ", " << rect.top_left_.first << "), "
				<< "w=" << rect.bottom_rigth_.second - rect.top_left_.second << ", "
				<< "h=" << rect.bottom_rigth_.first - rect.top_left_.first;

		return output;
	}

private:
	bool intersect(const rectangle& other) const {

		// Verifying if other is a valid rectangle
		if (!other) return false;

		// Verifying if other rectangle is under or above me
		if ((top_left_.first >= other.bottom_rigth_.first) ||
			(other.top_left_.first >= bottom_rigth_.first))
			return false;

		// Verifying if other rectangle is left or right of me 
		if ((top_left_.second >= other.bottom_rigth_.second) ||
			(other.top_left_.second >= bottom_rigth_.second))
			return false;

		return true;
	}

	ptr_t get_intersection(const rectangle& other) const {
		auto result = std::make_shared<rectangle>();

		if (intersect(other)) {
			int x = { 0 }, y = { 0 };

			// Getting top
			x = std::max(top_left_.first, other.top_left_.first);

			// Getting left
			y = std::max(top_left_.second, other.top_left_.second);

			// Saving top_left_;
			(*result).top_left_ = std::make_pair(x, y);

			// Getting bottom
			x = std::min(bottom_rigth_.first, other.bottom_rigth_.first);

			// Getting right
			y = std::min(bottom_rigth_.second, other.bottom_rigth_.second);

			// Saving bottom_right
			(*result).bottom_rigth_ = std::make_pair(x, y);

			(*result).valid_ = true;
		}

		return result;
	}

	bool valid_ = { false };
	std::pair<int, int> top_left_ = { 0, 0 };
	std::pair<int, int> bottom_rigth_ = { 0, 0 };
};

class rectangles_mactches {
public:
	void add_rectangle(rectangle::ptr_t new_rect) {
		rectangles_.push_back(new_rect);
	}

	void print_intersections() {
		build_intersections();
		std::cout << "Input :" << std::endl;
		for (size_t idx = { 0 }; idx < rectangles_.size(); idx++) {
			std::cout << '\t' << idx + 1 << ": Rectangle " << (*rectangles_[idx]) << std::endl;
		}
		std::cout << std::endl << "Intersections" << std::endl;
		for (const auto &intersection : intersections_) {
			std::cout << '\t' << "Between rectangle ";
			for (size_t idx = 0; idx < intersection.parents.size(); idx++) {
				if (idx < intersection.parents.size() - 1) {
					std::cout << intersection.parents[idx] + 1;
					if (idx < intersection.parents.size() - 2)
						std::cout << ", ";
				}
				else
					std::cout << " and " << intersection.parents[idx] + 1;
			}
			std::cout << " " << (*intersection.rect) << std::endl;
		}
	}
private:
	using rectangles_vector_t = std::vector<rectangle::ptr_t >;

	struct interaction_item {
		interaction_item(rectangle::ptr_t r_) : rect(r_) {}
		rectangle::ptr_t rect;
		std::vector<int> parents;
	};

	void build_intersections() {
		int level = { 0 };
		while (build_intersections(level++));
	}

	bool build_intersections(unsigned int level) {
		if (!level) {
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
			return true;
		} else {
			std::vector<interaction_item> news_intersections;
			for (size_t idx = { 0 }; idx < rectangles_.size(); idx++) {
				for (const auto &item : intersections_) {
					if (item.parents.size() >= level + 1) {
						if (std::find(item.parents.begin(), item.parents.end(), idx) == item.parents.end()) {
							if ((*item.rect) & (*rectangles_[idx])) {
								std::vector<int> new_parents = item.parents;
								new_parents.push_back(idx);
								std::sort(new_parents.begin(), new_parents.end());
								bool found = { false };
								if (!found) {
									for (const auto &verify_item : news_intersections) {
										if (std::equal(new_parents.begin(), new_parents.end(), verify_item.parents.begin()))
											found = true;
									}
								}
								if (found)
									continue;
								interaction_item new_item((*item.rect) && (*rectangles_[idx]));
								new_item.parents = new_parents;
								news_intersections.push_back(new_item);
							}
						}
					}
				}
			}
			if (news_intersections.size()) {
				intersections_.insert(intersections_.end(), news_intersections.begin(), news_intersections.end());
				return true;
			}
		}
		return false;
	}

	rectangles_vector_t rectangles_;
	std::vector<interaction_item> intersections_;

};

int main(int argc, char* argv[]) {

	rectangles_mactches rect_macthes;

	rect_macthes.add_rectangle(std::make_shared<rectangle>(100, 100, 250,  80));
	rect_macthes.add_rectangle(std::make_shared<rectangle>(120, 200, 250, 150));
	rect_macthes.add_rectangle(std::make_shared<rectangle>(140, 160, 250, 100));
	rect_macthes.add_rectangle(std::make_shared<rectangle>(160, 140, 350, 190));
	rect_macthes.add_rectangle(std::make_shared<rectangle>(290, 240, 100, 200));

	rect_macthes.print_intersections();

	return 0;
}