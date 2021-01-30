#pragma once

#include "CoreMinimal.h"
#include "PathNode.h"
#include "WeightPathNodeRef.h"
#include "Point.h"

class GGJ_2021_API MapRow
{
public:
	std::vector<PathNode> Columns;
};

/**
 * 
 */
class GGJ_2021_API TileMap
{
public:
	//int Test;
	//std::priority_queue<int, PathNode> nodes;
	float TileSpeeds[(int)TileType::Size];
	std::vector<MapRow> Rows;
	int MapWidth = 20;
	int MapHeight = 40;

	TileMap();
	~TileMap();

	std::vector<WeightPathNodeRef> SelectTilesAroundTile(int centerX, int centerY);

	float CalculateHeuristic(float x1, float y1, float x2, float y2);
	float CalculateHeuristic(Point p1, Point p2);

	std::vector<PathNode*> SelectAstarPath(Point start, Point end);
	
};
