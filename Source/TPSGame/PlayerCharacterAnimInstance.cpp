
#include "PlayerCharacterAnimInstance.h"

#include "PlayerCharacter.h"


void UPlayerCharacterAnimInstance::NativeBeginPlay()
{
	Character = Cast<APlayerCharacter>(TryGetPawnOwner());

	if (Character)
	{
		Mesh = Character->GetMesh();
		Character->CurrentWeaponChangedDelegate.AddDynamic(this, &UPlayerCharacterAnimInstance::CurrentWeaponChanged);
		CurrentWeaponChanged(Character->CurrentWeapon, nullptr);
	}
}

void UPlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	
}

void UPlayerCharacterAnimInstance::CurrentWeaponChanged(class AWeapon* NewWeapon, const class AWeapon* OldWeapon)
{
	CurrentWeapon = NewWeapon;
	if (CurrentWeapon)
	{
		IKProperties = CurrentWeapon->IKProperties;
	}
}