#include <rectangles_matches.h>
#include <functional>
#include <fstream>
#include <json.hpp>

// As purposed: "The JSON file may contain any number of input rectangles. 
// Your program must be able to process JSON files containing at least 10 
// rectangles. You may discard the remaining rectangles 
// after the first 10." - from Purpose file
#define MIN_RECT 10
#define MAX_RECT 15

// Function to read the file content
std::string read_data(std::istream& in) {
	std::stringstream out_str;
	while (in.good()) {
		std::string line;
		std::getline(in, line);
		out_str << line;
	}
	return out_str.str();
}

int main(int argc, char* argv[]) {

	// Json file content
	std::string json_buffer;

	if (argc > 1) {
		// The input file has been passed in the command line.
		// Read the data from it.
		std::ifstream ifile(argv[1]);
		if (ifile) {
			json_buffer = read_data(ifile);
		} else {
			std::cerr << "Error when opening the json file" << std::endl;
			return -1;
		}
	} else {
		// No input file has been passed in the command line.
		// Read the data from stdin (std::cin).
		std::cerr << "If nothing happens press [Ctrl+C]. Usage: app rects.json";
		json_buffer = read_data(std::cin);
		std::cerr << "\r                                                          \r";
	}

	if (json_buffer == "") {
		std::cerr << "This file is empty" << std::endl;
		return -1;
	}

	try {
		rectangles_matches rect_macthes;
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
			rectangle rect((*j_rect)["x"], (*j_rect)["y"], (*j_rect)["w"], (*j_rect)["h"]);
			if (!rect_macthes.add_rectangle(rect)) {
				std::cerr << "Error when inserting rectangle " << rect << std::endl;
				return -1;
			}
		}

		// Print the result
		std::cout << rect_macthes;

		return 0;
	} catch (nlohmann::json::exception& e) {
		std::cerr << "Something wrong with json content: " << std::endl
			<< e.what() << std::endl;
	}
	return -1;
}