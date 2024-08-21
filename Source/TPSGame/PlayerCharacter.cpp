#include "PlayerCharacter.h"
#include "Weapon.h"

#include "Engine/Classes/Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include <Runtime/Engine/Public/Net/UnrealNetwork.h>

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->bUsePawnControlRotation = true;
	Camera->SetupAttachment(GetMesh(), FName("head"));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if(HasAuthority())
	{
		for (const TSubclassOf<AWeapon>& WeaponClass : DefaultWeapons)
		{
			if (!WeaponClass) continue;
			FActorSpawnParameters params;
			params.Owner = this;
			AWeapon* spawnedWeapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass, params);
			const int32 index = Weapons.Add(spawnedWeapon);
			if (index == CurrentIndex)
			{
				CurrentWeapon = spawnedWeapon;
				OnRepCurrentWeapon(nullptr);
			}
		}
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(FName("NextWeapon"), IE_Pressed, this, &APlayerCharacter::NextWeapon);
	PlayerInputComponent->BindAction(FName("LastWeapon"), IE_Pressed, this, &APlayerCharacter::LastWeapon);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &APlayerCharacter::LookRight);
}

void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(APlayerCharacter, Weapons, COND_None);
	DOREPLIFETIME_CONDITION(APlayerCharacter, CurrentWeapon, COND_None);
}

void APlayerCharacter::OnRepCurrentWeapon(const AWeapon* OldWeapon)
{
	if (CurrentWeapon)
	{
		if (!CurrentWeapon->CurrentOwner)
		{
			const FTransform& PlacementTransform = CurrentWeapon->PlacementTransform * GetMesh()->GetSocketTransform(FName("hand_r"));
			CurrentWeapon->SetActorTransform(PlacementTransform, false, nullptr, ETeleportType::TeleportPhysics);
			CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepWorldTransform, FName("hand_r"));

			CurrentWeapon->CurrentOwner = this;
		}
		CurrentWeapon->Mesh->SetVisibility(true);
	}

	if (OldWeapon)
	{
		OldWeapon->Mesh->SetVisibility(true);
	}

	CurrentWeaponChangedDelegate.Broadcast(CurrentWeapon, OldWeapon);
}

void APlayerCharacter::EquipWeapon(const int32 Index)
{
	if (!Weapons.IsValidIndex(Index) || CurrentWeapon == Weapons[Index]) return;

	if (IsLocallyControlled())
	{
		CurrentIndex = Index;

		const AWeapon* oldWeapon = CurrentWeapon;
		CurrentWeapon = Weapons[Index];
		OnRepCurrentWeapon(oldWeapon);
	}
	else if (!HasAuthority())
	{
		Server_SetCurrentWeapon(Weapons[Index]);
	}
}

void APlayerCharacter::Server_SetCurrentWeapon_Implementation(class AWeapon* NewWeapon)
{
	const AWeapon* oldWeapon = CurrentWeapon;
	CurrentWeapon = NewWeapon;
	OnRepCurrentWeapon(oldWeapon);
}

void APlayerCharacter::NextWeapon()
{
	const int32 Index = Weapons.IsValidIndex(CurrentIndex + 1) ? (CurrentIndex + 1) : 0;
	EquipWeapon(Index);
}

void APlayerCharacter::LastWeapon()
{
	const int32 Index = Weapons.IsValidIndex(CurrentIndex - 1) ? (CurrentIndex - 1) : (Weapons.Num() - 1);
	EquipWeapon(Index);
}

void APlayerCharacter::MoveForward(const float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void APlayerCharacter::MoveRight(const float value)
{
	AddMovementInput(GetActorRightVector() * value);
}

void APlayerCharacter::LookUp(const float value)
{
	AddControllerPitchInput(value);
}

void APlayerCharacter::LookRight(const float value)
{
	AddControllerYawInput(value);
}

