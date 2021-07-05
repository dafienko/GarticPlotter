#pragma once

#include <string>

#include "Vector2i.h"

void setCursorPos(Vector2i pos);
void setCursorPos(int x, int y);
Vector2i getMousePos();

void mouseDown();
void mouseUp();
void mouseClick();

bool fileExists(std::string path);