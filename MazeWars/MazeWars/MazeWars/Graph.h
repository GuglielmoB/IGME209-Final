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
	map<Vertex, vector<Vertex>> adjList;
	Graph();
	~Graph();


	vector<Vertex> neighbors(Vertex id, map<Vertex, vector<Vertex>> adjList);
	float heuristic(Vertex a, Vertex b);
	void aStar(Graph graph, Vertex start, Vertex goal, map<Vertex, vector<Vertex>> adjList);
};

