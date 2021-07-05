#include <stdio.h>
#include <iostream>
#include <cmath>

#include "stb_image.h"
#include "GarticGame.h"
#include "Vector2i.h"
#include "winUtil.h"

std::string progressBarStr(float alpha) {
	std::string str = "";
	int num_chars = 35;
	for (int i = 0; i < num_chars; i++) {
		if (alpha > i / (float)num_chars) {
			str = str + "#";
		}
		else {
			str = str + "-";
		}
	}

	return str;
}

void printProgressBar(float alpha) {
	printf("\r [%s] %.2f%%    ", progressBarStr(alpha).c_str(), alpha * 100.0f);
}


GarticGame::GarticGame() : imageResolution{ .1f } {

}

void GarticGame::updateBounds() {
	/*
		ui element ratios:

		palette:
		0.01713, 0.2735
		0.12939, 0.62815

		canvas:
		0.14995, 0.20451
		0.84575, 0.80743

		toolbox:
		0.87574, 0.284196
		0.97686, 0.71713
	*/
	const float GAME_ASPECT = 1.54f;

	Vector2i size = bottomRight - topLeft;

	palette.setTopLeft(topLeft + Vector2i(size.x * 0.01713f, size.y * 0.2735f));
	palette.setBottomRight(topLeft + Vector2i(size.x * 0.12939f, size.y * 0.62815f));

	canvas.setTopLeft(topLeft + Vector2i(size.x * 0.14995f, size.y * 0.20451f));
	canvas.setBottomRight(topLeft + Vector2i(size.x * 0.84575f, size.y * 0.80743f));

	toolbox.setTopLeft(topLeft + Vector2i(size.x * 0.87574f, size.y * 0.284196f));
	toolbox.setBottomRight(topLeft + Vector2i(size.x * 0.97686f, size.y * 0.71713f));
}

void GarticGame::setTopLeft(Vector2i pos) {
	topLeft = pos;
	printf("game top left set to (%i, %i)\n", pos.x, pos.y);
	updateBounds();
}

void GarticGame::setBottomRight(Vector2i pos) {
	bottomRight = pos;
	printf("game bottom right set to (%i, %i)\n", pos.x, pos.y);
	updateBounds();
}

void GarticGame::clear() {
	toolbox.setTool(ERASER);

	Vector2i size = canvas.getSize();
	int resolution = 25;
	for (int y = 0; y < size.y; y += resolution) {
		for (int x = 0; x < size.x; x += resolution) {
			canvas.plot(Vector2i(x, y));
			printProgressBar((float)(y * size.x + x) / (float)(size.x * size.y));

		}
	}

	printProgressBar(1.0f);
	printf("done\n");
}

void GarticGame::drawImage(std::string filename) {
	toolbox.setTool(PEN);

	std::string assetDir = "assets\\" + filename;
	if (!fileExists(assetDir)) {
		printf("file not found\n");
		return;
	}

	int width, height, channels;
	unsigned char* img = stbi_load(assetDir.c_str(), &width, &height, &channels, 3);

	Vector2i startPos;
	Vector2i imgScreenSize;
	Vector2i canvasSize = canvas.getSize();
	
	float imageAspect = (float)width / (float)height;
	float screenAspect = (float)canvasSize.x / (float)canvasSize.y;
	if (imageAspect > screenAspect) { 
		imgScreenSize = Vector2i(
			canvasSize.x,
			canvasSize.x / imageAspect
		);
		startPos = Vector2i(0, (canvasSize.y - imgScreenSize.y) / 2);
	}
	else {
		imgScreenSize = Vector2i(
			canvasSize.y * imageAspect,
			canvasSize.y
		);
		startPos = Vector2i((canvasSize.x - imgScreenSize.x) / 2, 0);
	}

	
	int resolution = imgScreenSize.x / (canvasSize.x * imageResolution);
	int pauseInterval = 5;
	int lineNumber = 0;
	float numSamples = imgScreenSize.x * imgScreenSize.y;
	for (int y = 0; y < imgScreenSize.y; y += resolution) {
		for (int x = 0; x < imgScreenSize.x; x += resolution) {
			int sx = (x / (float)imgScreenSize.x) * width;
			int sy = (y / (float)imgScreenSize.y) * height;

			int sampleIndex = sy * width + sx;
			unsigned char* thisPixel = img + sampleIndex * 3;

			int r = (int)*(thisPixel + 0);
			int g = (int)*(thisPixel + 1);
			int b = (int)*(thisPixel + 2);

			plotColor(Vector2i(startPos.x + x, startPos.y + y), Color3(r, g, b));

			float progress = fminf((float)(y * imgScreenSize.x + x) / numSamples, 1.0f);
			printProgressBar(progress);
		}

		if (lineNumber % pauseInterval == 0) {
			printf("continue? (type exit to cancel)\n");
			std::string line = "";
			std::getline(std::cin, line);
			pauseInterval *= 3;

			if (line == "exit") {
				break;
			}
		}
		lineNumber++;
	}

	printProgressBar(1.0f);
	printf("done\n");
	stbi_image_free(img);
}

void GarticGame::plotColor(Vector2i pos, Color3 c) {
	toolbox.setTool(PEN);
	palette.selectColor(c);
	if (palette.getCurrentColor() != palette.getBackgroundColor()) {
		canvas.plot(pos);
	}
}

void GarticGame::setBackgroundColor(Color3 c) {
	toolbox.setTool(BUCKET);
	palette.selectColor(c);
	canvas.plot(Vector2i(30, 30));
}