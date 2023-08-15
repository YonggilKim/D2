// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/D2CharacterBase.h"
// Sets default values
AD2CharacterBase::AD2CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled((ECollisionEnabled::NoCollision));
}

// Called when the game starts or when spawned
void AD2CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AD2CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AD2CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


float AD2CharacterBase::GetHealth()
{
	return _health;
}

float AD2CharacterBase::GetMaxHealth()
{
	return _maxHealth;
}

void AD2CharacterBase::SetMaxHealth(float value)
{ 
	_maxHealth = value;
}

float AD2CharacterBase::GetMana()
{
	return _mana;
}

void AD2CharacterBase::SetMana(float value)
{
	_mana = value;
}

float AD2CharacterBase::GetMaxMana()
{
	return _maxMana;
}

void AD2CharacterBase::SetMaxMana(float value)
{
	_maxMana = value;
}

float AD2CharacterBase::GetAttack()
{
	return _attack;
}

void AD2CharacterBase::SetAttack(float value)
{
	_attack = value;
}


void AD2CharacterBase::SetHealth(float value)
{
	_health = value;
}

FVector AD2CharacterBase::GetCombatSocketLocation()
{
	check(Weapon);
	return Weapon->GetSocketLocation(WeaponTipSocketName);
}

void AD2CharacterBase::SpawnProjectile(const FVector& ProjectileTargetLocation)
{
	const FVector SocketLocation = GetCombatSocketLocation();

	//TODO: Set the Projectile Rotation
	FRotator Rotation = (ProjectileTargetLocation - SocketLocation).Rotation();
	Rotation.Pitch = 0.f;

	FTransform SpawnTransform;
	SpawnTransform.SetLocation(SocketLocation);
	SpawnTransform.SetRotation(Rotation.Quaternion());

	AD2Projectile* Projectile = GetWorld()->SpawnActorDeferred<AD2Projectile>(
		ProjectileClass,
		SpawnTransform,
		this,
		Cast<APawn>(this),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

	Projectile->FinishSpawning(SpawnTransform);
}
