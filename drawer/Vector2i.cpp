#include "Vector2i.h"

Vector2i::Vector2i() {
	Vector2i(0, 0);
}

Vector2i::Vector2i(int x, int y) : x(x), y(y) {}

Vector2i Vector2i::operator+(const Vector2i& right) const {
	return Vector2i(this->x + right.x, this->y + right.y);
}

Vector2i Vector2i::operator-(const Vector2i& right) const {
	return Vector2i(this->x - right.x, this->y - right.y);
}

