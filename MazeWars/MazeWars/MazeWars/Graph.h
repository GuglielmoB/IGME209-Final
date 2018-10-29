#pragma once
#include <iostream> 
#include <vector> 
#include "Vertex.h"
using namespace std;

class Graph
{
public:
	vector<Vertex> vertices;
	int** adjacencyMatrix;
	Graph();
	~Graph();
};

