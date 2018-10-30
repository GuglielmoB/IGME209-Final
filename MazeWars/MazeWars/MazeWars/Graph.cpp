#include "stdafx.h"
#include "Graph.h"
#include <iostream> 
#include <list>
#include <queue>
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

	const_iterator find(const T&val) const
	{
		auto first = this->c.cbegin();
		auto last = this->c.cend();
		while (first != last) {
			if (*first == val) return first;
			++first;
		}
		return last;
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


Graph::~Graph()
{
}

vector<Vertex> Graph::neighbors(Vertex id, map<Vertex, vector<Vertex>> adjList)
{
	return adjList[id];
}

float Graph::heuristic(Vertex a, Vertex b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void Graph::aStar(Graph graph, Vertex start, Vertex goal, map<Vertex, vector<Vertex>> adjList)
{
	vector<Vertex> SolutionPathList;

	//Create OPEN and CLOSED list
	PriorityQueue<Vertex, double> OPEN;
	list<Vertex> CLOSED;

	//Put start on the OPEN list
	start.h = heuristic(start, goal);
	OPEN.put(start, start.h);

	//while the OPEN list is not empty
	while (OPEN.elements.size > 0)
	{
		//Get the vertex off the open list
		//with the lowest f and call it current
		Vertex current = OPEN.get();

		// IF IS GOAL
		if (current.x == goal.x && current.y == goal.y)
		{
			// MAKE PATH FROM GOAL TO START
			break;
		}

		//Generate each state node_successor that can come after node_current
		vector<Vertex> neighbors = graph.neighbors(current, adjList);

		//for each node_successor or node_current
		for (Vertex neighbor : neighbors)
		{
			//Cost = G(CURRENT) + cost of CURRENT to neighbor
			float cost = heuristic(start, current) + heuristic(current, neighbor);

			//find node_successor on the OPEN list
			bool oFound = OPEN.find(neighbor);

			if (oFound && cost < heuristic(start, neighbor))
			{
				// remove neighbor
				OPEN.remove(neighbor);
			}

			//find node_successor on the CLOSED list
			bool cFound = (std::find(CLOSED.begin(), CLOSED.end(), neighbor) != CLOSED.end());

			if (cFound && cost < heuristic(start, neighbor))
			{
				// remove neighbor
				CLOSED.remove(neighbor);
			}

			if (!oFound && !cFound) {
				//Add node_successor to the OPEN list
				neighbor.lowestCost = cost;
				OPEN.put(neighbor, cost + heuristic(neighbor, goal));
				current = neighbor;
			}
		}
		//Add node_current to the CLOSED list
		CLOSED.push_back(current);
	}
}
