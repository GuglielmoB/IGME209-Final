#include "stdafx.h"
#include "Graph.h"
#include <iostream> 
#include <list>
#include <queue>
using namespace std;

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

double Graph::heuristic(Vertex a, Vertex b) {
	return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

void Graph::a_star_search(Graph graph, Vertex start, Vertex goal, map<Vertex, vector<Vertex>> adjList)
{
	vector<Vertex> SolutionPathList;

	//Create OPEN and CLOSED list
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> OPEN;
	list<Vertex> CLOSED;

	//Put node_start on the OPEN list
	OPEN.push(start);

	//while the OPEN list is not empty
	while (OPEN.size > 0)
	{
		//Get the node off the open list
		//with the lowest f and call it node_current
		Vertex node_current = OPEN.top;
		OPEN.pop();

		CLOSED.push_back(node_current);

		//if node_current is the same state as node_goal we
		//have found the solution;
		//break from the while loop;
		if (node_current.x == goal.x && node_current.y == goal.y)
		{
			break;
		}

		//Generate each state node_successor that can come after node_current
		vector<Vertex> neighbors = graph.neighbors(node_current, adjList);

		//for each node_successor or node_current
		for (Vertex neighbor : neighbors)
		{
			//Set the cost of node_successor to be the cost of node_current plus
			//the cost to get to node_successor from node_current
			//--> already set while we were getting successors

			//find node_successor on the OPEN list
			vector<int>::iterator it;

			//if node_successor is on the OPEN list but the existing one is as good
			//or better then discard this successor and continue

			if (oFound > 0 && cost < G(neighbor))
			{
				//remove from open
			}


			//find node_successor on the CLOSED list
			bool cFound = (std::find(CLOSED.begin(), CLOSED.end(), neighbor) != CLOSED.end());

			//if node_successor is on the CLOSED list
			//but the existing one is as good
			//or better then discard this successor and continue;
			if (cFound && cost < G(neighbor))
			{
				// remove from closed
			}

			if (!oFound && !cFound) {
			
				//Add node_successor to the OPEN list
				OPEN.push(node_successor);
			}
			

		}
		//Add node_current to the CLOSED list
		CLOSED.push_back(node_current);
}
