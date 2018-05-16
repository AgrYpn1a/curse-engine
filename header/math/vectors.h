#pragma once
#include <cmath>

struct vector2
{
	int _x;
	int _y;

	vector2() {}
	vector2(int x, int y): _x{x}, _y{y} {}

	float length()
	{
		return std::sqrt(_x*_x + _y*_y);
	}

	vector2 normalize()
	{
		return vector2(_x / length(), _y / length());
	}

	vector2& operator+(const vector2& v)
	{
		_x = _x + v._x;
		_y = _y + v._y;

		return *this;
	}
};

struct vector3
{
	int x;
	int y;
	int z;
};
