// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Point.h"
#include "HexTile2.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GGJ_2021_API UHexTile2 : public UStaticMeshComponent
{
	GENERATED_BODY()

public: 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FLinearColor HexColor;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Height = 1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool Enabled;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Index;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInstanceDynamic *MaterialInstance;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FIntPoint PositionInGrid;


	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "RandomColor"))
	void RandomColor();
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "IncrementHeight"))
	void IncrementHeight();

	void BeginPlay() override;
};
