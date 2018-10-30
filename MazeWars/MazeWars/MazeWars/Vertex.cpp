#include "stdafx.h"
#include "Vertex.h"
#include <math.h>


Vertex::Vertex()
{
}

Vertex::Vertex(Vertex parent, Vertex goal, int gCost, int x, int y)
{
	parentX = parent.x;
	parentY = parent.y;
	goalX = goal.x;
	goalY = goal.x;
	gCost = gCost;
	x = x;
	y = y;
	g = (parent.g != NULL) ? parent.g + gCost : gCost;
	h = (goal.h != NULL) ? (int) sqrt(((x - goal.x)*(x - goal.x)) + (y - goal.y)*(y - goal.y)) : 0;
}


Vertex::~Vertex()
{
}

