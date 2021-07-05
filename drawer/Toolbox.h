#pragma once

#include "Vector2i.h"
#include "GridContainer.h"

enum TOOL {
	PEN,
	ERASER,
	RECT,
	CIRCLE,
	RECTFILL,
	CIRCLEFILL,
	LINE,
	BUCKET,
	UNDO,
	REDO
};

class Toolbox: public GridContainer {
private:
	TOOL currentTool;
public:
	Toolbox();
	void setTool(TOOL tool);
};