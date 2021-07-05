#pragma once

#include <string>

#include "Canvas.h"
#include "Toolbox.h"
#include "ColorPalette.h"

class GarticGame {
private:
	ColorPalette palette;
	Toolbox toolbox;
	Canvas canvas;
	Vector2i topLeft, bottomRight;

	void updateBounds();
public:
	float imageResolution;

	GarticGame();

	void setTopLeft(Vector2i pos);
	void setBottomRight(Vector2i pos);

	void setBackgroundColor(Color3 c);

	void clear();
	void drawImage(std::string imageName);

	void plotColor(Vector2i pos, Color3 c);
};