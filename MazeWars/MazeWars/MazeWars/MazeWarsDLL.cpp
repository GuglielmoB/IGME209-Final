// MazeWarsDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "stdio.h"
#include "Vertex.h"
#include "Graph.h"
#include <iostream> 
#include <vector> 
using namespace std;

__declspec(dllexport) const int** dllmaze;
__declspec(dllexport) int mazeWidth;
__declspec(dllexport) int mazeHeight;
__declspec(dllexport) int startX;
__declspec(dllexport) int startY;
__declspec(dllexport) int endX;
__declspec(dllexport) int endY;
__declspec(dllexport) char* teamString;
__declspec(dllexport) int xPositions[10] = {9, 3, 4, 6, 1, 8, 2, 5, 7, 0};
__declspec(dllexport) int yPositions[10] = {6, 4, 3, 7, 1, 2, 8, 9, 5, 0};
__declspec(dllexport) int iterate = 0;
__declspec(dllexport) int** adjMatrix;
__declspec(dllexport) Graph graph;
__declspec(dllexport) vector<Vertex> vertices;
__declspec(dllexport) vector<Vertex> path;
__declspec(dllexport) bool pathMade = false;
__declspec(dllexport) bool teamName = false;


__declspec(dllexport) char* GetTeam()
{
	const char* teamMembers = "John Castaneda & Brandon Guglielmo\n";
	teamString = new char[strlen(teamMembers) + 1];
	strcpy_s(teamString, strlen(teamMembers) + 1,  teamMembers);
	teamName = true;
	return teamString;
}

__declspec(dllexport) bool SetMaze(const int** data, int width, int height)
{
	if (data != NULL && data != nullptr && width > 0 && height > 0) {
		// Team name and members should be printed by now, delete.
		if (teamName) {
			delete teamString;
			teamName = false;
		}

		dllmaze = data;
		mazeWidth = width;
		mazeHeight = height;
		pathMade = false;

		adjMatrix = new int*[mazeWidth]; // for the graph

		for (int i = 0; i < mazeWidth; ++i) {
			adjMatrix[i] = new int[mazeHeight];
		}

		for (int x = 0; x < mazeWidth; x++) {
			for (int y = 0; y < mazeHeight; y++) {
				adjMatrix[x][y] = dllmaze[x][y];

				if (adjMatrix[x][y] == 0) {
					Vertex toAdd = Vertex(x, y, 0, 0);
					vertices.push_back(toAdd);
				}
			}
		}

		graph = Graph(vertices, adjMatrix, mazeWidth, mazeHeight); // create graph

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
		int** returnMaze = new int*[mazeWidth];

		for (int i = 0; i < mazeWidth; ++i) {
			returnMaze[i] = new int[mazeHeight];
		}

		for (int x = 0; x < mazeWidth; x++) {
			for (int y = 0; y < mazeHeight; y++) {
				returnMaze[x][y] = dllmaze[x][y];
			}
		}

		return returnMaze;
	}
}

__declspec(dllexport) bool GetNextPosition(int& xpos, int& ypos)
{
	if (!pathMade) {
		iterate = 0;
		path = graph.aStar(graph, Vertex(startX, startY, 0, 0), Vertex(endX, endY, 0, 0), vertices, adjMatrix);
		pathMade = true;

		//adjacency matrix no longer needed, so delete!
		for (int d = 0; d < mazeWidth; d++) {
			delete[] adjMatrix[d];
		}
		delete[] adjMatrix;
	}

	if (iterate < path.size()) {
		xpos = path[iterate].x;
		ypos = path[iterate].y;
		iterate++;
		return true;
	}
	else {
		return false;
	}
	
}

__declspec(dllexport) bool SetStart(int xpos, int ypos)
{
	if (xpos < mazeWidth && ypos < mazeHeight && xpos >= 0 && ypos >= 0) {
		startX = xpos;
		startY = ypos;
		pathMade = false;

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
	if (xpos < mazeWidth && ypos < mazeHeight && xpos >= 0 && ypos >= 0) {
		endX = xpos;
		endY = ypos;
		pathMade = false;

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
	iterate = 0;
	return true;
}
