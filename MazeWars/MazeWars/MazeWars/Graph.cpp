#include "stdafx.h"
#include "Graph.h"
#include <iostream> 
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

template<typename T, typename priority_t>
struct PriorityQueue {
	typedef std::pair<priority_t, T> PQElement;
	std::priority_queue<PQElement, std::vector<PQElement>,
		std::greater<PQElement>> elements;

	inline bool empty() const {
		return elements.empty();
	}

	inline void put(T item, priority_t priority) {
		elements.emplace(priority, item);
	}

	T get() {
		T best_item = elements.top().second;
		elements.pop();
		return best_item;
	}

	bool find(const T& value) {
		auto it = std::find(this->c.begin(), this->c.end(), value);
		if (it != this->c.end()) {
			return true;
		}
		else {
			return false;
		}
	}

	bool remove(const T& value) {
		auto it = std::find(this->c.begin(), this->c.end(), value);
		if (it != this->c.end()) {
			this->c.erase(it);
			std::make_heap(this->c.begin(), this->c.end(), this->comp);
			return true;
		}
		else {
			return false;
		}
	}
};

Graph::Graph()
{
}

Graph::Graph(vector<Vertex> vert, int ** adj)
{
	vertices = vert;
	adjList = adj;
}


Graph::~Graph()
{
}

vector<Vertex> Graph::neighbors(Vertex id, vector<Vertex> vertices, int** adjList)
{
	vector<Vertex> successors;
	Vertex v;
	if (adjList[id.x + 1][id.y] == 1)
	{
		int x = id.x + 1;
		int y = id.y;
		auto it = find_if(vertices.begin(), vertices.end(), [&x, &y](const Vertex& obj) {return obj.x == x + 1 && obj.y == y; });

		if (it != vertices.end())
		{
			auto index = std::distance(vertices.begin(), it);
			successors.push_back(vertices[index]);
		}
	}
		
	if (adjList[id.x - 1][id.y] == 1)
	{
		int x = id.x - 1;
		int y = id.y;
		auto it = find_if(vertices.begin(), vertices.end(), [&x, &y](const Vertex& obj) {return obj.x == x + 1 && obj.y == y; });

		if (it != vertices.end())
		{
			auto index = std::distance(vertices.begin(), it);
			successors.push_back(vertices[index]);
		}
	}

	if (adjList[id.x][id.y + 1] == 1)
	{
		int x = id.x;
		int y = id.y + 1;
		auto it = find_if(vertices.begin(), vertices.end(), [&x, &y](const Vertex& obj) {return obj.x == x + 1 && obj.y == y; });

		if (it != vertices.end())
		{
			auto index = std::distance(vertices.begin(), it);
			successors.push_back(vertices[index]);
		}
	}
	
	if (adjList[id.x][id.y - 1] == 1)
	{
		int x = id.x;
		int y = id.y - 1;
		auto it = find_if(vertices.begin(), vertices.end(), [&x, &y](const Vertex& obj) {return obj.x == x + 1 && obj.y == y; });

		if (it != vertices.end())
		{
			auto index = std::distance(vertices.begin(), it);
			successors.push_back(vertices[index]);
		}
	}

	return successors;
}

int Graph::heuristic(Vertex a, Vertex b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void Graph::aStar(Graph graph, Vertex start, Vertex goal, vector<Vertex> vertices, int** adjList, vector<Vertex> path)
{
	//Create OPEN and CLOSED list
	PriorityQueue<Vertex, double> OPEN;
	list<Vertex> CLOSED;

	//Put start on the OPEN list
	start.h = heuristic(start, goal);
	OPEN.put(start, start.h);

	//while the OPEN list is not empty
	while (OPEN.elements.size() > 0)
	{
		//Get the vertex off the open list
		//with the lowest f and call it current
		Vertex current = OPEN.get();

		// IF IS GOAL
		if (current.x == goal.x && current.y == goal.y)
		{
			Vertex pathMaker = goal;
			while (pathMaker.parent != NULL) {
				path.insert(path.begin(), pathMaker);
				pathMaker = *pathMaker.parent;
			}
		}

		//Generate each state node_successor that can come after node_current
		vector<Vertex> neighbors = graph.neighbors(current, vertices, adjList);

		//for each node_successor or node_current
		for (Vertex neighbor : neighbors)
		{
			//Cost = G(CURRENT) + cost of CURRENT to neighbor
			int cost = heuristic(start, current) + heuristic(current, neighbor);

			//find node_successor on the OPEN list
			bool oFound = OPEN.find(neighbor);

			if (oFound && cost < heuristic(start, neighbor))
			{
				// remove neighbor
				OPEN.remove(neighbor);
			}

			//find node_successor on the CLOSED list
			int neighX = neighbor.x;
			int neighY = neighbor.y;
			// bool cFound = (std::find(CLOSED.begin(), CLOSED.end(), neighbor) != CLOSED.end());
			bool cFound;
			auto it = find_if(CLOSED.begin(), CLOSED.end(), [&neighX, &neighY](const Vertex& obj) {return obj.x == neighX && obj.y == neighY; });
			if (it != CLOSED.end()) {
				cFound = true;
			}
			else {
				cFound = false;
			}

			if (cFound && cost < heuristic(start, neighbor))
			{
				// remove neighbor
				CLOSED.remove(neighbor);
			}

			if (!oFound && !cFound) {
				//Add node_successor to the OPEN list
				neighbor.lowestCost = cost;
				OPEN.put(neighbor, cost + heuristic(neighbor, goal));
				neighbor.parent = &current;
				current = neighbor;
			}
		}
		//Add node_current to the CLOSED list
		CLOSED.push_back(current);
	}
}
