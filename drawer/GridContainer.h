#pragma once

#include "Vector2i.h"

class GridContainer {
private:
	const int gridWidth, gridHeight;
	Vector2i topLeft, bottomRight;
	void selectItemAtPosition(Vector2i gridPos);
public:
	void setTopLeft(Vector2i pos);
	void setBottomRight(Vector2i pos);
	void selectItem(int item);

	GridContainer(Vector2i gridSize);
};