// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileMap.h"
#include "HexTile2.h"
#include "HexMap.generated.h"

UCLASS()
class GGJ_2021_API AHexMap : public AActor
{
public:
	GENERATED_BODY()

public:
	//UPROPERTY(BlueprintReadWrite, EditAnywhere)
	//UStaticMesh* mesh;
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UStaticMesh> HexMeshPtr;
	UStaticMesh* HexMesh;
	TileMap TileMap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UHexTile2*> tiles;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int GridX = 10;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int GridY = 10;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SpacingX = 110;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SpacingY = 100;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Offset = 55;

	FScriptDelegate onClickDelegate;

public:	
	// Sets default values for this actor's properties
	AHexMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;
	UFUNCTION(BlueprintCallable, CallInEditor)
	void GenerateGrid();
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "OnHexClick"))
	virtual void OnHexClick(UPrimitiveComponent* componenentClicked, FKey button);
};
