#include "Toolbox.h"
#include "winUtil.h"
#include <stdio.h>

Toolbox::Toolbox() : GridContainer(Vector2i(2, 5)), currentTool{ PEN } {

}

void Toolbox::setTool(TOOL tool) {
	if (tool != currentTool) {
		selectItem((int)tool);
		currentTool = tool;
	}
}

