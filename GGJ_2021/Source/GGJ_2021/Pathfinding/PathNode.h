// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeightPathNodeRef.h"

enum struct TileType :int
{
	Regular,
	Wall,

	Size //used to init the array size
};

/**
 * 
 */
class GGJ_2021_API PathNode
{
public:
	bool Enabled;
	TileType TileType;
	std::vector<WeightPathNodeRef> ConnectedNodes;
	int X;
	int Y;

	PathNode();
	~PathNode();
};
