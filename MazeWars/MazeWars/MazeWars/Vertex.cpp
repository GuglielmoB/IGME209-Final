#include "stdafx.h"
#include "Vertex.h"
#include <math.h>


Vertex::Vertex()
{
}

Vertex::Vertex(int xPos, int yPos, int heu, int cost)
{
	x = xPos;
	y = yPos;
	h = heu;
	lowestCost = cost;
}

Vertex::~Vertex()
{
}

