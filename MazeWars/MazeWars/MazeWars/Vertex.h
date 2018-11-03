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
	Vertex(int xPos, int yPos, int heu, int cost);
	~Vertex();
};

