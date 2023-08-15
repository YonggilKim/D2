// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/D2Projectile.h"
#include "GameFramework/Character.h"
#include "Interfaces/CombatInterface.h"
#include "GameFramework/ProjectileMovementComponent.h" 

#include "D2CharacterBase.generated.h"

UCLASS()
class D2_API AD2CharacterBase : public ACharacter,  public ICombatInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AD2CharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

private:
	float _health = 100;
	float _maxHealth = 100;
	float _mana = 50;
	float _maxMana = 50;
	float _attack = 10;

public:
	float GetHealth();
	virtual void SetHealth(float value);

	float GetMaxHealth();
	virtual void SetMaxHealth(float value);

	float GetMana();
	virtual void SetMana(float value);

	float GetMaxMana();
	virtual void SetMaxMana(float value);

	float GetAttack();
	 virtual void SetAttack(float value);

public:
	virtual FVector GetCombatSocketLocation() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	FName WeaponTipSocketName;

	
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SpawnProjectile(const FVector& ProjectileTargetLocation);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AD2Projectile> ProjectileClass;
};
