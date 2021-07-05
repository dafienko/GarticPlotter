#include "Canvas.h"
#include "winUtil.h"

#include <stdio.h>
#include <cmath>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Canvas::Canvas() {

}

void Canvas::updateSize() {
	size = bottomRight - topLeft;
}

void Canvas::setTopLeft(Vector2i pos) {
	printf("canvas top left set to (%i, %i)\n", pos.x, pos.y);
	topLeft = pos;
	updateSize();
}

void Canvas::setBottomRight(Vector2i pos) {
	printf("canvas bottom right set to (%i, %i)\n", pos.x, pos.y);
	bottomRight = pos;
	updateSize();
}

void Canvas::plot(Vector2i pos) {
	setCursorPos(pos.x + topLeft.x, pos.y + topLeft.y);
	mouseClick();
}

Vector2i Canvas::getSize() {
	return size;
}

