// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShootingGame_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ShootingGame;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ShootingGame()
	{
		if (!Z_Registration_Info_UPackage__Script_ShootingGame.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ShootingGame",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xF30FC525,
				0x5590C950,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ShootingGame.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ShootingGame.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ShootingGame(Z_Construct_UPackage__Script_ShootingGame, TEXT("/Script/ShootingGame"), Z_Registration_Info_UPackage__Script_ShootingGame, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xF30FC525, 0x5590C950));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
