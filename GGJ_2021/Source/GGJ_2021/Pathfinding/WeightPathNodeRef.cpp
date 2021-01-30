// Fill out your copyright notice in the Description page of Project Settings.


#include "WeightPathNodeRef.h"
#include "PathNode.h"

WeightPathNodeRef::WeightPathNodeRef(PathNode *pathNode, float weight)
	: PathNodeRef(pathNode)
	, Weight(weight)
{
}

WeightPathNodeRef::~WeightPathNodeRef()
{
}
