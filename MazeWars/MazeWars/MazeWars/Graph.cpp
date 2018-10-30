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

		//if node_current is the same state as node_goal we
		//have found the solution;
		//break from the while loop;
		if (node_current.x == goal.x && node_current.y == goal.y)
		{
			goal.parentX = node_current.parentX;
			goal.parentY = node_current.parentY;
			break;
		}

		//Generate each state node_successor that can come after node_current
		vector<Vertex> successors = neighbors(node_current, adjList);

		//for each node_successor or node_current
		for (Vertex node_successor : successors)
		{
			//Set the cost of node_successor to be the cost of node_current plus
			//the cost to get to node_successor from node_current
			//--> already set while we were getting successors

			//find node_successor on the OPEN list
			vector<Vertex> successors;

			for (int xd = -1; xd <= 1; xd++)
			{
				for (int yd = -1; yd <= 1; yd++)
				{
					if (Map.getMap(x + xd, y + yd) != -1)
					{
						Vertex n = new Vertex(this, this._goalNode, Map.getMap(x + xd, y + yd), x + xd, y + yd);
						if (!n.isMatch(this.parentNode) && !n.isMatch(this))
							successors.Add(n);

					}
				}
			}
			return successors;

			//if node_successor is on the OPEN list but the existing one is as good
			//or better then discard this successor and continue

			if (oFound > 0)
			{
				Node existing_node = OPEN.NodeAt(oFound);
				if (existing_node.CompareTo(node_current) <= 0)
					continue;
			}


			//find node_successor on the CLOSED list
			int cFound = CLOSED.IndexOf(node_successor);

			//if node_successor is on the CLOSED list
			//but the existing one is as good
			//or better then discard this successor and continue;
			if (cFound > 0)
			{
				Node existing_node = CLOSED.NodeAt(cFound);
				if (existing_node.CompareTo(node_current) <= 0)
					continue;
			}

			//Remove occurences of node_successor from OPEN and CLOSED
			if (oFound != -1)
				OPEN.RemoveAt(oFound);
			if (cFound != -1)
				CLOSED.RemoveAt(cFound);
			//Add node_successor to the OPEN list
			OPEN.push(node_successor);

		}
		//Add node_current to the CLOSED list
		CLOSED.push(node_current);
}
