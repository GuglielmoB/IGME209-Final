// MazeWarsDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "stdio.h"

__declspec(dllexport) char* GetTeam()
{
	char teamMembers[] = "John Castaneda & Brandon Guglielmo";
	return teamMembers;
}

__declspec(dllexport) const int** dllmaze;
__declspec(dllexport) int mazeWidth;
__declspec(dllexport) int mazeHeight;


__declspec(dllexport) void SetMaze(const int** data, int width, int height)
{
	dllmaze = data;
	mazeWidth = width;
	mazeHeight = height;
}

__declspec(dllexport) int** GetMaze(int& width, int& height)
{
	int** returnMaze;

	for (int i = 0; i < mazeWidth; i++) {
		for (int j = 0; j < mazeHeight; j++) {
			returnMaze[j][i] = dllmaze[j][i];
		}
	}

	return returnMaze;
}