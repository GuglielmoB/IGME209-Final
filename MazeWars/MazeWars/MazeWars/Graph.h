#pragma once
#include <iostream> 
#include <vector> 
#include <map> 
#include "Vertex.h"
using namespace std;

class Graph
{
public:
	vector<Vertex> vertices;
	int** adjMatrix;
	int graphWidth;
	int graphHeight;
	vector<Vertex> path;
	Graph();
	Graph(vector<Vertex> vertices, int** adjList, int graphWidth, int graphHeight);
	~Graph();


	vector<Vertex> neighbors(Vertex id, vector<Vertex> vertices, int** adjMatrix);
	int heuristic(Vertex a, Vertex b);
	vector<Vertex> aStar(Graph graph, Vertex start, Vertex goal, vector<Vertex> vertices, int** adjMatrix);
};

