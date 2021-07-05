#define _CRT_SECURE_NO_WARNINGS
#include "winUtil.h"

#include <Windows.h>
#include <Shlwapi.h>
#include <stdio.h>

#pragma comment(lib, "Shlwapi.lib")

Vector2i getMousePos() {
	POINT pt;
	GetCursorPos(&pt);

	return Vector2i(pt.x, pt.y);
}

void setCursorPos(Vector2i pos) {
	setCursorPos(pos.x, pos.y);
}

void setCursorPos(int x, int y) {
	SetCursorPos(x, y);
}

void mouseDown() {
	MOUSEINPUT mi = { 0 };
	mi.dx = 0;
	mi.dy = 0;
	mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	mi.dwExtraInfo = NULL;
	mi.mouseData = 0;
	mi.time = 0;

	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi = mi;

	SendInput(1, &input, sizeof(input));
}

void mouseUp() {
	MOUSEINPUT mi = { 0 };
	mi.dx = 0;
	mi.dy = 0;
	mi.dwFlags = MOUSEEVENTF_LEFTUP;
	mi.dwExtraInfo = NULL;
	mi.mouseData = 0;
	mi.time = 0;

	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi = mi;

	SendInput(1, &input, sizeof(input));
}

void mouseClick() {
	mouseDown();
	Sleep(1);
	mouseUp();
}


bool fileExists(std::string path) {
	FILE* file = fopen(path.c_str(), "r");
	if (file) {
		fclose(file);
		return true;
	}

	return false;
}