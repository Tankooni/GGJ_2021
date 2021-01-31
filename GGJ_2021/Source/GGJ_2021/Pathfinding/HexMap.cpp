// Fill out your copyright notice in the Description page of Project Settings.


#include "HexMap.h"

// Sets default values
AHexMap::AHexMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	onClickDelegate.BindUFunction(this, "OnHexClick");
}

// Called when the game starts or when spawned
void AHexMap::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Begin play"));
	
}

// Called every frame
void AHexMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHexMap::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	GenerateGrid();
}

void AHexMap::GenerateGrid()
{
	HexMesh = HexMeshPtr.Get();
	if (!IsValid(HexMesh))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Hex Map mesh is null"));
		return;
	}

	for (int i = tiles.Num() - 1; i >= 0; i--)
	{
		if(tiles[i] != nullptr)
			tiles[i]->DestroyComponent();
	}

	tiles.Reset(0);

	for (int y = 0; y < GridY; y++)
	{
		int rowOffset = (y % 2 == 1) ? Offset : 0;
		for (int x = 0; x < GridX; x++)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString("X:" + FString::FromInt(x) + ", Y:" + FString::FromInt(y)));
			UHexTile2* hexTileCmpt = NewObject<UHexTile2>(this, UHexTile2::StaticClass(), FName(FString("X:" + FString::FromInt(x) + ",Y:" + FString::FromInt(y))));
			hexTileCmpt->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
			hexTileCmpt->SetStaticMesh(HexMesh);
			hexTileCmpt->RegisterComponent();

			hexTileCmpt->SetRelativeLocation(FVector(x * SpacingX + rowOffset, y * SpacingY, 0));
			hexTileCmpt->SetRelativeRotation(FRotator(0, 90, 0));

			hexTileCmpt->OnClicked.AddUnique(onClickDelegate);


			tiles.Add(hexTileCmpt);
		}
	}
}

void AHexMap::OnHexClick(UPrimitiveComponent* componenentClicked, FKey button)
{
	check(false);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Clicked"));
}

