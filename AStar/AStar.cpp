#include "AStar.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// STL A* Search implementation
// (C)2001 Justin Heyes-Jones
//
// Finding a path on a simple grid maze
// This shows how to do shortest path finding using A*

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdio.h>

#define DEBUG_LISTS 0
#define DEBUG_LIST_LENGTHS_ONLY 0

using namespace std;

// Global data

// The world map

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 20;

// map helper functions

int GetMap(int x, int y)
{
	if (x < 0 ||
		x >= MAP_WIDTH ||
		y < 0 ||
		y >= MAP_HEIGHT
		)
	{
		return 9;
	}

	return world_map[(y*MAP_WIDTH) + x];
}



// Definitions

class MapSearchNode
{
public:
	int x;	 // the (x,y) positions of the node
	int y;

	MapSearchNode() { x = y = 0; }
	MapSearchNode(int px, int py) { x = px; y = py; }

	float GoalDistanceEstimate(MapSearchNode &nodeGoal);
	bool IsGoal(MapSearchNode &nodeGoal);
	float GetCost(MapSearchNode &successor);
	bool IsSameState(MapSearchNode &rhs);

	void PrintNodeInfo();


};

bool MapSearchNode::IsSameState(MapSearchNode &rhs)
{

	// same state in a maze search is simply when (x,y) are the same
	if ((x == rhs.x) &&
		(y == rhs.y))
	{
		return true;
	}
	else
	{
		return false;
	}

}




AStar::AStar()
{
}


AStar::~AStar()
{
}
