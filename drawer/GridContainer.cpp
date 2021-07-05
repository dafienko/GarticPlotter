#include "GridContainer.h"
#include "winUtil.h"

GridContainer::GridContainer(Vector2i gridSize) : gridWidth{ gridSize.x }, gridHeight{ gridSize.y } {

}

void GridContainer::setTopLeft(Vector2i pos) {
	topLeft = pos;
}

void GridContainer::setBottomRight(Vector2i pos) {
	bottomRight = pos;
}


void GridContainer::selectItemAtPosition(Vector2i gridPos) {
	Vector2i screenSize = bottomRight - topLeft;
	int iw = screenSize.x / gridWidth;
	int ih = screenSize.y / gridHeight;

	setCursorPos(topLeft.x + iw / 2 + gridPos.x * iw, topLeft.y + ih / 2 + gridPos.y * ih);
	mouseClick();
}

void GridContainer::selectItem(int item) {
	selectItemAtPosition(Vector2i(item % gridWidth, item / gridWidth));
}