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
	int** adjList;
	vector<Vertex> path;
	Graph();
	Graph(vector<Vertex> vertices, int** adjList);
	~Graph();


	vector<Vertex> neighbors(Vertex id, vector<Vertex> vertices, int** adjList);
	int heuristic(Vertex a, Vertex b);
	void aStar(Graph graph, Vertex start, Vertex goal, vector<Vertex> vertices, int** adjList, vector<Vertex> path);
};

