#include "ColorPalette.h"

#include <cmath>

#include "winUtil.h"

Color3::Color3(float r, float g, float b) : r{ r }, g{ g }, b{ b } {}

Color3::Color3(int ri, int gi, int bi)  {
	r = ri / 255.0f;
	g = gi / 255.0f;
	b = bi / 255.0f;
}

float Color3::distanceToColor(Color3 c) {
	return sqrtf(powf(c.r - r, 2.0f) + powf(c.g - g, 2.0f) + powf(c.b - b, 2.0f));
}



Color3 paletteColors[] = {
	Color3(0, 0, 0),
	Color3(103, 103, 103),
	Color3(0, 80, 205),

	Color3(255, 255, 255),
	Color3(170, 170, 170),
	Color3(38, 201, 255),

	Color3(1, 116, 32),
	Color3(105, 21, 6),
	Color3(150, 65, 18),

	Color3(17, 176, 60),
	Color3(255, 0, 19),
	Color3(255, 120, 41),

	Color3(176, 112, 18),
	Color3(153, 0, 78),
	Color3(203, 909, 87),

	Color3(255, 193, 38),
	Color3(255, 0, 143),
	Color3(254, 175, 168)
};

ColorPalette::ColorPalette(): GridContainer(Vector2i(3, 6)) {  
	currentColor = BLACK;
	backgroundColor = WHITE;
}


void ColorPalette::selectColor(PaletteColor color) {
	if (color != currentColor) {
		currentColor = color;
		selectItem((int)color);
	}
}


PaletteColor getClosestPaletteColor(Color3 c) {
	PaletteColor closest;
	float dist = 2;

	for (int p = BLACK; p <= SKIN; p++) {
		Color3 actualColor = paletteColors[p];
		float d = c.distanceToColor(actualColor);

		if (d < dist) {
			dist = d;
			closest = (PaletteColor)p;
		}
	}

	return closest;
}

void ColorPalette::selectColor(Color3 color) {
	selectColor(getClosestPaletteColor(color));
}

void ColorPalette::setBackgroundColor(PaletteColor c) {
	backgroundColor = c;
}

PaletteColor ColorPalette::getCurrentColor() {
	return currentColor;
}

PaletteColor ColorPalette::getBackgroundColor() {
	return backgroundColor;
}