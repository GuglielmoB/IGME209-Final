#include "stdafx.h"
#include "Vertex.h"
#include <math.h>


Vertex::Vertex()
{
}

Vertex::~Vertex()
{
}

bool operator==(Vertex & lhs, Vertex & rhs)
{
	return (&lhs.x == &rhs.x && &lhs.y == &rhs.y);
}
