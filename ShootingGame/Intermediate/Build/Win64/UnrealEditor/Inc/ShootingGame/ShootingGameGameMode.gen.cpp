// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShootingGame/ShootingGameGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShootingGameGameMode() {}
// Cross Module References
	SHOOTINGGAME_API UClass* Z_Construct_UClass_AShootingGameGameMode_NoRegister();
	SHOOTINGGAME_API UClass* Z_Construct_UClass_AShootingGameGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ShootingGame();
// End Cross Module References
	void AShootingGameGameMode::StaticRegisterNativesAShootingGameGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AShootingGameGameMode);
	UClass* Z_Construct_UClass_AShootingGameGameMode_NoRegister()
	{
		return AShootingGameGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AShootingGameGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShootingGameGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ShootingGame,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShootingGameGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ShootingGameGameMode.h" },
		{ "ModuleRelativePath", "ShootingGameGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShootingGameGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShootingGameGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AShootingGameGameMode_Statics::ClassParams = {
		&AShootingGameGameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AShootingGameGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AShootingGameGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShootingGameGameMode()
	{
		if (!Z_Registration_Info_UClass_AShootingGameGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AShootingGameGameMode.OuterSingleton, Z_Construct_UClass_AShootingGameGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AShootingGameGameMode.OuterSingleton;
	}
	template<> SHOOTINGGAME_API UClass* StaticClass<AShootingGameGameMode>()
	{
		return AShootingGameGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShootingGameGameMode);
	struct Z_CompiledInDeferFile_FID_ShootingGame_Source_ShootingGame_ShootingGameGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ShootingGame_Source_ShootingGame_ShootingGameGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AShootingGameGameMode, AShootingGameGameMode::StaticClass, TEXT("AShootingGameGameMode"), &Z_Registration_Info_UClass_AShootingGameGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AShootingGameGameMode), 2239240938U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ShootingGame_Source_ShootingGame_ShootingGameGameMode_h_684940845(TEXT("/Script/ShootingGame"),
		Z_CompiledInDeferFile_FID_ShootingGame_Source_ShootingGame_ShootingGameGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ShootingGame_Source_ShootingGame_ShootingGameGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
