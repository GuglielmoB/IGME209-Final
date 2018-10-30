#pragma once
class Vertex
{
public:
	float g;
	float h;
	int x;
	int y;
	int goalX;
	int goalY;
	int parentX;
	int parentY;
	int gCost;
	Vertex();
	Vertex(Vertex parent, Vertex goal, int gCost, int x, int y);
	~Vertex();
};

