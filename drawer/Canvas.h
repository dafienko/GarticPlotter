#pragma once

#include <string>

#include "Vector2i.h"
#include "ColorPalette.h"

class Canvas {
private:
	Vector2i topLeft, bottomRight, size;
	PaletteColor backgroundColor;


	void updateSize();

public:
	Canvas();

	void setTopLeft(Vector2i bound);
	void setBottomRight(Vector2i bound);

	Vector2i getSize();

	void plot(Vector2i pos);
};