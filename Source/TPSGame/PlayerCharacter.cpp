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

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &APlayerCharacter::LookRight);
}

void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(APlayerCharacter, Weapons, COND_None);
}

void APlayerCharacter::OnRepCurrentWeapon(const AWeapon* oldWeapon)
{
	if (CurrentWeapon)
	{
		if (!CurrentWeapon->CurrentOwner)
		{
			CurrentWeapon->SetActorTransform(GetMesh()->GetSocketTransform(FName("CurrentWeapon")), false, nullptr, ETeleportType::TeleportPhysics);
			CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepWorldTransform, FName("Weapon_R"));
		}
	}

	if (oldWeapon)
	{

	}
}

void APlayerCharacter::MoveForward(const float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void APlayerCharacter::MoveRight(const float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void APlayerCharacter::LookUp(const float value)
{
	AddControllerPitchInput(value);
}

void APlayerCharacter::LookRight(const float value)
{
	AddControllerYawInput(value);
}

