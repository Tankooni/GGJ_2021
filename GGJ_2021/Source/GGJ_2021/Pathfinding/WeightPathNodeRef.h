// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
class PathNode;

/**
 * 
 */
class GGJ_2021_API WeightPathNodeRef
{
public:
	PathNode *PathNodeRef;
	float Weight;

	WeightPathNodeRef(PathNode *pathNode, float weight);
	~WeightPathNodeRef();
};
