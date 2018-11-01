#pragma once
class Vertex
{
public:
	int x;
	int y;
	int h;
	Vertex* parent;
	int lowestCost;	
	Vertex();
	Vertex(int x, int y, int h, int lowestCost);
	~Vertex();
	friend bool operator== (Vertex & lhs, Vertex & rhs);
};

