// MazeWarsDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "stdio.h"

__declspec(dllexport) const int** dllmaze;
__declspec(dllexport) int mazeWidth;
__declspec(dllexport) int mazeHeight;
__declspec(dllexport) int startX;
__declspec(dllexport) int startY;
__declspec(dllexport) int endX;
__declspec(dllexport) int endY;
__declspec(dllexport) int xPositions[10] = {9, 3, 4, 6, 1, 8, 2, 5, 7, 0};
__declspec(dllexport) int yPositions[10] = {6, 4, 3, 7, 1, 2, 8, 9, 5, 0};
__declspec(dllexport) int iterate = 0;


__declspec(dllexport) char* GetTeam()
{
	const char* teamMembers = "John Castaneda & Brandon Guglielmo";
	char* teamString = new char[strlen(teamMembers) + 1];
	strcpy_s(teamString, strlen(teamMembers) + 1,  teamMembers);
	return teamString;
}

__declspec(dllexport) bool SetMaze(const int** data, int width, int height)
{
	dllmaze = data;
	if (width > 0 && height > 0) {
		mazeWidth = width;
		mazeHeight = height;
		return true;
	}
	else {
		return false;
	}
}

__declspec(dllexport) int** GetMaze(int& width, int& height)
{
	width = mazeWidth;
	height = mazeHeight;
	if (dllmaze == NULL) {
		return nullptr;
	}
	else {
		int** returnMaze = new int*[mazeHeight];
		for (int i = 0; i < mazeHeight; ++i) {
			returnMaze[i] = new int[mazeWidth];
		}

		for (int y = 0; y < mazeHeight; y++) {
			for (int x = 0; x < mazeWidth; x++) {
				returnMaze[y][x] = dllmaze[y][x];
			}
		}
		return returnMaze;
	}
}

__declspec(dllexport) bool GetNextPosition(int& xpos, int& ypos)
{
	if (iterate < (sizeof(xPositions) / sizeof(*xPositions))) {
		xpos = xPositions[iterate];
		ypos = yPositions[iterate];
		iterate++;
		return true;
	}
	else {
		return false;
	}
	
}

__declspec(dllexport) bool SetStart(int xpos, int ypos)
{
	if (xpos < mazeWidth && ypos < mazeHeight) {
		startX = xpos;
		startY = ypos;
		return true;
	}
	else {
		return false;
	}
}

__declspec(dllexport) bool GetStart(int& xpos, int& ypos)
{
	if (startX != NULL && startY != NULL) {
		xpos = startX;
		ypos = startY;
		return true;
	}
	else {
		return false;
	}
}

__declspec(dllexport) bool SetEnd(int xpos, int ypos)
{
	if (xpos < mazeWidth && ypos < mazeHeight) {
		endX = xpos;
		endY = ypos;
		return true;
	}
	else {
		return false;
	}
}

__declspec(dllexport) bool GetEnd(int& xpos, int& ypos)
{
	if (endX != NULL && endY != NULL) {
		xpos = endX;
		ypos = endY;
		return true;
	}
	else {
		return false;
	}
}

__declspec(dllexport) bool Restart()
{
	return true;
}
