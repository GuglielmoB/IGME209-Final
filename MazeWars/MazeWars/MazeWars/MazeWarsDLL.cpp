// MazeWarsDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "stdio.h"

__declspec(dllexport) char* GetTeam()
{
	char teamMembers[] = "John Castaneda & Brandon Guglielmo";
	return teamMembers;
}

__declspec(dllexport) int mytestvar[50][50];

__declspec(dllexport) void SetMaze(const int** data, int width, int height)
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			mytestvar[j][i] == data[j][i];
		}
	}
}

__declspec(dllexport) int** GetMaze(int width, int height)
{
	return mytestvar;
}