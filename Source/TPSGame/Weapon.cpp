#include "Weapon.h"

#include "Engine/Classes/Components/SkeletalMeshComponent.h"


AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	SetReplicates(true);

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	if(!CurrentOwner) Mesh->SetVisibility(false);
}
