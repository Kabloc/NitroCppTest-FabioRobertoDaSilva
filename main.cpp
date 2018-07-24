#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <sstream>

class rectangle {
public:
	rectangle() { }

	rectangle(int x, int y, unsigned int w, unsigned int h) 
		: top_left{ y, x }
		, bottom_rigth{ y + h, x + w } {

		// If it is zero sized, it will be invalidated
		valid_ = !(!w || !h);
	}

	explicit operator bool() const { return valid_; }

	//~rectangle() { valid_ = false; }

	friend bool operator&(const rectangle& lRect, const rectangle& rRect) {
		return lRect.intersect(rRect);
	}

	friend const rectangle& operator&&(const rectangle& lRect, const rectangle& rRect) {
		return lRect.get_intersection(rRect);
	}

	friend std::ostream& operator<<(std::ostream& output, const rectangle& rect) {
		// (top, left), w=left-right, h=bottom-top
		if (!rect)
			output << "at (?, ?), w=?, h=?";
		else
			output << "at (" << rect.top_left.second << ", " << rect.top_left.first << "), "
				<< "w=" << rect.bottom_rigth.second - rect.top_left.second << ", "
				<< "h=" << rect.bottom_rigth.first - rect.top_left.first;

		return output;
	}

private:
	bool intersect(const rectangle& other) const {

		// Verifying if other is a valid rectangle
		if (!other) return false;

		// Verifying if other rectangle is under or above me
		if ((top_left.first >= other.bottom_rigth.first) ||
			(other.top_left.first >= bottom_rigth.first))
			return false;

		// Verifying if other rectangle is left or right of me 
		if ((top_left.second >= other.bottom_rigth.second) ||
			(other.top_left.second >= bottom_rigth.second))
			return false;

		return true;
	}

	const rectangle& get_intersection(const rectangle& other) const {
		rectangle result;

		if (intersect(other)) {
			int x, y;

			// Getting top
			x = std::max(top_left.first, other.top_left.first);

			// Getting left
			y = std::max(top_left.second, other.top_left.second);

			// Saving top_left;
			result.top_left = std::make_pair(x, y);

			// Getting bottom
			x = std::min(bottom_rigth.first, other.bottom_rigth.first);

			// Getting right
			y = std::min(bottom_rigth.second, other.bottom_rigth.second);

			// Saving bottom_right
			result.bottom_rigth = std::make_pair(x, y);

			result.valid_ = true;
		}

		return result;
	}

	bool valid_ = { false };
	std::pair<int, int> top_left = { 0, 0 };
	std::pair<int, int> bottom_rigth = { 0, 0 };
};

int main(int argc, char* argv[]) {
	std::vector<std::pair<std::string, rectangle> > rectangles, intersections;

	rectangles.push_back(std::make_pair("1", rectangle(100, 100, 250, 80)));
	rectangles.push_back(std::make_pair("2", rectangle(120, 200, 250, 150)));
	rectangles.push_back(std::make_pair("3", rectangle(140, 160, 250, 100)));
	rectangles.push_back(std::make_pair("4", rectangle(160, 140, 350, 190)));

	std::cout << "Input :" << std::endl;
	for (auto &rect : rectangles) {
		std::cout << '\t' << rect.first << ": Rectangle " << rect.second << std::endl;
	}

	std::cout << "Intersections" << std::endl;
	for (auto rectA = rectangles.begin(); rectA != rectangles.end(); rectA++) {
		for (auto rectB = rectA+1; rectB != rectangles.end(); rectB++) {
			if ((*rectA).second & (*rectB).second) {
				std::stringstream ss;
				rectangle aux(((*rectA).second && (*rectB).second));
				ss << (*rectA).first << ", " << (*rectB).first;
				intersections.push_back(std::make_pair(ss.str(), aux));
				std::cout << '\t' << "Between rectangle " << (*rectA).first << " and " << (*rectB).first
					<< " " << aux << std::endl;
			}
		}
	}

	return 0;
}