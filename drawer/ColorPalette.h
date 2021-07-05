#pragma once

#include "Vector2i.h"
#include "GridContainer.h"

class Color3 {
private:
	float r, g, b;
public:
	Color3(float r, float g, float b);
	Color3(int r, int g, int b);

	float distanceToColor(Color3 c);
};

enum PaletteColor {
	BLACK,
	DKGRAY,
	BLUE,
	
	WHITE,
	LTGRAY,
	LTBLUE,

	GREEN,
	DKBROWN,
	BROWN,

	LTGREEN,
	RED,
	ORANGE,

	LTBROWN,
	PURPLE,
	MAROON,

	YELLOW,
	PINK,
	SKIN
};

class ColorPalette: public GridContainer {
private:
	PaletteColor backgroundColor;
	PaletteColor currentColor;
public:
	ColorPalette();

	void selectColor(PaletteColor);
	void selectColor(Color3);
	PaletteColor getCurrentColor();

	void setBackgroundColor(PaletteColor c);
	PaletteColor getBackgroundColor();
};