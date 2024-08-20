#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "PlayerCharacter.generated.h"

UCLASS()
class TPSGAME_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class UCameraComponent* Camera;


protected:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TArray<TSubclassOf<class AWeapon>> DefaultWeapons;


public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Replicated, Category = "State")
	TArray<class AWeapon*> Weapons;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, ReplicatedUsing = OnRepCurrentWeapon, Category = "State")
	class AWeapon* CurrentWeapon;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Replicated, Category = "State")
	int32 CurrentIndex = 0;


protected:
	UFUNCTION()
	virtual void OnRepCurrentWeapon(const class AWeapon* oldWeapon);





protected:
	void MoveForward(const float value);
	void MoveRight(const float value);
	void LookUp(const float value);
	void LookRight(const float value);
};
