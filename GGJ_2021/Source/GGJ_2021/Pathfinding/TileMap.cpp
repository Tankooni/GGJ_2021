#include "TileMap.h"
#include <map>

namespace
{
	struct PriorityPathNodePtr
	{
		PathNode* PathNodePtr;
		float Priority;

		friend bool operator< (const PriorityPathNodePtr& lPathNode, const PriorityPathNodePtr& rPathNode)
		{
			return lPathNode.Priority < rPathNode.Priority;
		}
		friend bool operator> (const PriorityPathNodePtr& lPathNode, const PriorityPathNodePtr& rPathNode)
		{
			return lPathNode.Priority > rPathNode.Priority;
		}
		friend bool operator<= (const PriorityPathNodePtr& lPathNode, const PriorityPathNodePtr& rPathNode)
		{
			return lPathNode.Priority <= rPathNode.Priority;
		}
		friend bool operator>= (const PriorityPathNodePtr& lPathNode, const PriorityPathNodePtr& rPathNode)
		{
			return lPathNode.Priority >= rPathNode.Priority;
		}
		friend bool operator== (const PriorityPathNodePtr& lPathNode, const PriorityPathNodePtr& rPathNode)
		{
			return lPathNode.Priority == rPathNode.Priority;
		}
		friend bool operator!= (const PriorityPathNodePtr& lPathNode, const PriorityPathNodePtr& rPathNode)
		{
			return lPathNode.Priority != rPathNode.Priority;
		}
	};
}


const static Point evenRelPosToCheck[] =
{
	Point(0, -2),
	Point(0, 2),
	Point(0, -1),
	Point(-1, -1),
	Point(0, 1),
	Point(0, -2),
	Point(-1, 1),
};
const static Point oddRelPosToCheck[] =
{
	Point(0, -2),
	Point(0, 2),
	Point(0, -1),
	Point(1, -1),
	Point(0, 1),
	Point(0, -2),
	Point(1, 1),
};

TileMap::TileMap()
{
	TileSpeeds[(int)TileType::Regular] = 0;
	TileSpeeds[(int)TileType::Wall] = 1;
}

TileMap::~TileMap()
{
}

std::vector<WeightPathNodeRef> TileMap::SelectTilesAroundTile(int centerX, int centerY)
{
	std::vector<WeightPathNodeRef> nodes;

	for (const auto &checkPosition : centerY % 2 == 0 ? evenRelPosToCheck : oddRelPosToCheck)
	{
		int y = checkPosition.Y + centerY;
		if (y < 0 || y >= Rows.size())
			continue;
		int x = checkPosition.X + centerX;
		if (x < 0 || x >= Rows[y].Columns.size())
			continue;
		
		PathNode *pathNode = &(Rows[y].Columns[x]);
		float weight = TileSpeeds[(int)pathNode->TileType];
		if (weight <= 0 || !pathNode->Enabled)
			continue;
		nodes.emplace_back(WeightPathNodeRef(pathNode, weight));
	}

	return nodes;
}

float TileMap::CalculateHeuristic(float x1, float y1, float x2, float y2)
{
	return FMath::Abs(x1 - x2) - FMath::Abs(y1 - y2);
}

float TileMap::CalculateHeuristic(Point p1, Point p2)
{
	return FMath::Abs(p1.X - p2.X) - FMath::Abs(p1.Y - p2.Y);
}

std::vector<PathNode*> TileMap::SelectAstarPath(Point start, Point end)
{
	PathNode *startNode = &(Rows[start.X].Columns[start.Y]);
	PathNode *endNode = &(Rows[end.X].Columns[end.Y]);
	std::priority_queue<PriorityPathNodePtr> frontier;

	frontier.push({ startNode, 0 });

	std::map<PathNode*, PathNode*> cameFrom;
	std::map<PathNode*, float> costSoFar;

	cameFrom[startNode] = nullptr;
	costSoFar[startNode] = 0;

	if (startNode->X != endNode->X && startNode->Y != endNode->Y)
	{
		while (!frontier.empty())
		{
			PathNode* current = frontier.top().PathNodePtr;
			frontier.pop();
			for (auto next : current->ConnectedNodes)
			{
				float newCost = costSoFar[current] + next.Weight;
				if (costSoFar.count(current) == 0)
					costSoFar[current] = newCost;
				else if (newCost < costSoFar[current])
					costSoFar[current] = newCost;
				else
					continue;

				float priority = newCost + CalculateHeuristic(endNode->X, endNode->Y, startNode->X, startNode->Y);
				frontier.push({ next.PathNodeRef, priority });

				cameFrom[next.PathNodeRef] = current;
			}
		}
	}

	std::vector<PathNode*> path;

	PathNode* currentNode = endNode;
	if (cameFrom.count(currentNode) > 0)
		path.push_back(currentNode);
	while (startNode->X != endNode->X || startNode->Y != endNode->Y)
	{
		if (cameFrom.count(currentNode) > 0)
		{
			currentNode = cameFrom[currentNode];
			path.push_back(currentNode);
		}
		else
			break;
	}

	return path;
}
