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
	char teamMembers[] = "John Castaneda & Brandon Guglielmo";
	return &teamMembers;
}

__declspec(dllexport) void SetMaze(const int** data, int width, int height)
{
	dllmaze = data;
	mazeWidth = width;
	mazeHeight = height;
}

__declspec(dllexport) int** GetMaze(int& width, int& height)
{
	width = mazeWidth;
	height = mazeHeight;
	int** returnMaze = (int**)dllmaze;
	return returnMaze;
}

__declspec(dllexport) void GetNextPosition(int& xpos, int& ypos)
{
	xpos = xPositions[iterate];
	ypos = yPositions[iterate];

	iterate++;
}

__declspec(dllexport) void SetStart(int xpos, int ypos)
{
	startX = xpos;
	startY = ypos;
}

__declspec(dllexport) void GetStart(int& xpos, int& ypos)
{
	xpos = startX;
	ypos = startY;
}

__declspec(dllexport) void SetEnd(int xpos, int ypos)
{
	endX = xpos;
	endY = ypos;
}

__declspec(dllexport) void GetEnd(int& xpos, int& ypos)
{
	xpos = endX;
	ypos = endY;
}
