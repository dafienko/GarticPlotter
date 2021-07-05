#pragma once

class Vector2i {
public:
	int x, y;

	Vector2i();
	Vector2i(int x, int y);

	Vector2i operator+(const Vector2i& right) const;
	Vector2i operator-(const Vector2i& right) const;
};