// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GGJ_2021/GGJ_2021GameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGGJ_2021GameMode() {}
// Cross Module References
	GGJ_2021_API UClass* Z_Construct_UClass_AGGJ_2021GameMode_NoRegister();
	GGJ_2021_API UClass* Z_Construct_UClass_AGGJ_2021GameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_GGJ_2021();
// End Cross Module References
	void AGGJ_2021GameMode::StaticRegisterNativesAGGJ_2021GameMode()
	{
	}
	UClass* Z_Construct_UClass_AGGJ_2021GameMode_NoRegister()
	{
		return AGGJ_2021GameMode::StaticClass();
	}
	struct Z_Construct_UClass_AGGJ_2021GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGGJ_2021GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GGJ_2021,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGGJ_2021GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "GGJ_2021GameMode.h" },
		{ "ModuleRelativePath", "GGJ_2021GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGGJ_2021GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGGJ_2021GameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGGJ_2021GameMode_Statics::ClassParams = {
		&AGGJ_2021GameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AGGJ_2021GameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGGJ_2021GameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGGJ_2021GameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGGJ_2021GameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGGJ_2021GameMode, 839908128);
	template<> GGJ_2021_API UClass* StaticClass<AGGJ_2021GameMode>()
	{
		return AGGJ_2021GameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGGJ_2021GameMode(Z_Construct_UClass_AGGJ_2021GameMode, &AGGJ_2021GameMode::StaticClass, TEXT("/Script/GGJ_2021"), TEXT("AGGJ_2021GameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGGJ_2021GameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
