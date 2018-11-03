#include "stdafx.h"
#include "Graph.h"
#include <iostream> 
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

Graph::Graph()
{
}

Graph::Graph(vector<Vertex> vert, int ** adj, int width, int height)
{
	vertices = vert;
	adjMatrix = adj;
	graphWidth = width;
	graphHeight = height;
}


Graph::~Graph()
{
}

vector<Vertex> Graph::neighbors(Vertex id, vector<Vertex> vertices, int** adjMatrix)
{
	vector<Vertex> successors;
	Vertex v;
	if (id.x + 1 < graphWidth) {
		if (adjMatrix[id.x + 1][id.y] == 0)
		{
			int x = id.x + 1;
			int y = id.y;
			auto it = find_if(vertices.begin(), vertices.end(), [&x, &y](const Vertex& obj) {return obj.x == x && obj.y == y; });

			if (it != vertices.end())
			{
				auto index = std::distance(vertices.begin(), it);
				successors.push_back(vertices[index]);
			}
		}
	}

	if (id.x - 1 >= 0) {
		if (adjMatrix[id.x - 1][id.y] == 0)
		{
			int x = id.x - 1;
			int y = id.y;
			auto it = find_if(vertices.begin(), vertices.end(), [&x, &y](const Vertex& obj) {return obj.x == x && obj.y == y; });

			if (it != vertices.end())
			{
				auto index = std::distance(vertices.begin(), it);
				successors.push_back(vertices[index]);
			}
		}
	}

	if (id.y + 1 < graphHeight) {
		if (adjMatrix[id.x][id.y + 1] == 0)
		{
			int x = id.x;
			int y = id.y + 1;
			auto it = find_if(vertices.begin(), vertices.end(), [&x, &y](const Vertex& obj) {return obj.x == x && obj.y == y; });

			if (it != vertices.end())
			{
				auto index = std::distance(vertices.begin(), it);
				successors.push_back(vertices[index]);
			}
		}
	}
	
	if (id.y - 1 >= 0) {
		if (adjMatrix[id.x][id.y - 1] == 0)
		{
			int x = id.x;
			int y = id.y - 1;
			auto it = find_if(vertices.begin(), vertices.end(), [&x, &y](const Vertex& obj) {return obj.x == x && obj.y == y; });

			if (it != vertices.end())
			{
				auto index = std::distance(vertices.begin(), it);
				successors.push_back(vertices[index]);
			}
		}
	}

	return successors;
}

int Graph::heuristic(Vertex a, Vertex b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

bool compareInterval(Vertex i1, Vertex i2)
{
	return (i1.lowestCost < i2.lowestCost);
}

vector<Vertex> Graph::aStar(Graph graph, Vertex start, Vertex goal, vector<Vertex> vertices, int** adjMatrix)
{
	//Create OPEN and CLOSED list
	vector<Vertex> OPEN;
	list<Vertex> CLOSED;

	//Put start on the OPEN list
	start.h = heuristic(start, goal);
	OPEN.push_back(start);


	//while the OPEN list is not empty
	while (OPEN.size() > 0)
	{
		//Sort OPEN based off of cost
		sort(OPEN.begin(), OPEN.end(), compareInterval);

		//Get the vertex off the open list
		//with the lowest f and call it current
		Vertex current = OPEN[0];
		OPEN.erase(OPEN.begin());

		//Add neighbor to the CLOSED list
		CLOSED.push_back(current);

		// IF IS GOAL
		if (current.x == goal.x && current.y == goal.y)
		{
			
			auto it = find_if(vertices.begin(), vertices.end(), [current](const Vertex& obj) {return obj.x == current.x && obj.y == current.y; });
			auto index = std::distance(vertices.begin(), it);
			Vertex pathMaker = vertices[index];

			while (pathMaker.parent != NULL) {
				
				graph.path.insert(graph.path.begin(), pathMaker);
				pathMaker = *pathMaker.parent;
			}
			
			return graph.path;
		}

		//Generate each state node_successor that can come after node_current
		vector<Vertex> neighbors = graph.neighbors(current, vertices, adjMatrix);

		// get cost of neighbors and add them to the vertex
		for (Vertex neighbor : neighbors) {
			neighbor.lowestCost = heuristic(start, current) + heuristic(current, neighbor) + heuristic(neighbor, goal);
			// F = G + H
		}
		
		// sort neighbors
		sort(neighbors.begin(), neighbors.end(), compareInterval);

		Vertex holdCurrent = current;
		//for each neighbor
		for (Vertex neighbor : neighbors)
		{
			//Cost = G(CURRENT) + cost of CURRENT to neighbor
			int cost = heuristic(start, current) + heuristic(current, neighbor);
			int neighX = neighbor.x;
			int neighY = neighbor.y;

			//find neighbor on the OPEN list
			auto it = find_if(OPEN.begin(), OPEN.end(), [&neighX, &neighY](const Vertex& obj) {return obj.x == neighX && obj.y == neighY; });

			bool oFound;
			if (it != OPEN.end()) {
				oFound = true;
			}
			else {
				oFound = false;
			}

			if (oFound && cost < heuristic(start, neighbor))
			{
				// remove neighbor
				OPEN.erase(it);
			}

			//find neighbor on the CLOSED list
			bool cFound;
			auto cit = find_if(CLOSED.begin(), CLOSED.end(), [&neighX, &neighY](const Vertex& obj) {return obj.x == neighX && obj.y == neighY; });
			if (cit != CLOSED.end()) {
				cFound = true;
			}
			else {
				cFound = false;
			}

			if (cFound && cost < heuristic(start, neighbor))
			{
				// remove neighbor
				CLOSED.erase(cit);
			}

			it = find_if(OPEN.begin(), OPEN.end(), [&neighX, &neighY](const Vertex& obj) {return obj.x == neighX && obj.y == neighY; });
			cit = find_if(CLOSED.begin(), CLOSED.end(), [&neighX, &neighY](const Vertex& obj) {return obj.x == neighX && obj.y == neighY; });
			if (it != OPEN.end()) {
				oFound = true;
			}
			else {
				oFound = false;
			}
			
			if (cit != CLOSED.end()) {
				cFound = true;
			}
			else {
				cFound = false;
			}

			if (!oFound && !cFound) {
				//Add neighbor to the OPEN list
				neighbor.lowestCost = cost + heuristic(neighbor, goal);
				OPEN.push_back(neighbor);
				
				if (true) {
					//FINDING THE CURRENT VERTEX IN THE VECTOR OF VERTICES
					auto pit = find_if(vertices.begin(), vertices.end(), [holdCurrent](const Vertex& obj) {return obj.x == holdCurrent.x && obj.y == holdCurrent.y; });
					auto nit = find_if(vertices.begin(), vertices.end(), [neighbor](const Vertex& obj) {return obj.x == neighbor.x && obj.y == neighbor.y; });

					if (pit != vertices.end())
					{
						auto pindex = std::distance(vertices.begin(), pit);
						auto nindex = std::distance(vertices.begin(), nit);

						vertices[nindex].parent = &vertices[pindex];
					}
					current = neighbor;
				}
			}
		}
	}

	vector<Vertex> emptyPath;
	return emptyPath; // no path found.
}
