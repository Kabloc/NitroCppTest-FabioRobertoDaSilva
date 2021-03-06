#pragma once
#ifndef _RECTANGLES_H_
#define _RECTANGLES_H_
#include <iostream>
#include <algorithm>
#include <memory>
#include <utility>
#include <sstream>
#include <vector>
#include <array>

class rectangle {
public:
	// Shared pointer, it will be useful to manage de memory
	using ptr_t = std::shared_ptr<rectangle>;

	// Default contructor will create a invalid rectangle
	rectangle() { }

	// Parametized constructor will create a rectangle and verify if
	// it is sized: 
	// "Width and height are always positive integers" - from Purpose file
	rectangle(int x, int y, int w, int h);

	// Useful to verify if it is valid
	explicit operator bool() const;

	// Equal operator
	bool operator==(const rectangle& another) const;

	// Operator << to make it easy to print the values
	friend std::ostream& operator<<(std::ostream& output, const rectangle& rect);

	// Used to verify if exist a valid intersection rectangle
	// between this and another rectangle.
	bool intersect(const rectangle& another) const;

	// Used to print the intersections as purposed
	const std::string to_string() const;

	// Used to create an valid intersection rectangle between 
	// this and another rectangle
	ptr_t get_intersection(const rectangle& another) const;

private:
	// To improve the readability
	enum VerticesNames {Top, Left, Bottom, Right};

	// Assignment operator 
	rectangle & operator=(const rectangle& another);

	// I prefer to save the vertices values 
	// to make easy to make the calculus 
	bool valid_ = { false };
	std::array<int, 4> vertices_ = { 0, 0, 0, 0};
};
#endif //_RECTANGLES_H_