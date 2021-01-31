// Fill out your copyright notice in the Description page of Project Settings.


#include "HexTile2.h"

void UHexTile2::RandomColor()
{
	//HexColor
	HexColor.R = FMath::RandRange(0.0f, 1.0f);
	HexColor.G = FMath::RandRange(0.0f, 1.0f);
	HexColor.B = FMath::RandRange(0.0f, 1.0f);
	

	if (::IsValid(MaterialInstance))
	{
		MaterialInstance->UMaterialInstanceDynamic::SetVectorParameterValue(FName(TEXT("Color")), HexColor);
	}
}

void UHexTile2::IncrementHeight()
{
	if (Height > 5)
		Height = 1;
	else
		Height++;

	SetWorldScale3D(FVector(1, 1, Height));
}

void UHexTile2::BeginPlay()
{
	Super::BeginPlay();
	MaterialInstance = CreateDynamicMaterialInstance(0, ((UMaterialInterface*)nullptr), FName(TEXT("None")));
	//Oncli
}
