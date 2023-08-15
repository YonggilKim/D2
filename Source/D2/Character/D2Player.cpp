// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/D2Player.h"
#include "Gameframework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Gameframework/CharacterMovementComponent.h"
	

AD2Player::AD2Player()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 750.f;
	CameraBoom->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->bEnableCameraLag = true;
	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritRoll = false;
	CameraBoom->bInheritYaw = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>("Follow Camera");
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->bUsePawnControlRotation = false;

}

void AD2Player::SetMaxHealth(float value)
{
	Super::SetMaxHealth(value);

	if(OnPlayerStat_Changed.IsBound() == true)
		OnPlayerStat_Changed.Execute();
}

void AD2Player::SetHealth(float value)
{
	Super::SetHealth(value);
	
	if(OnPlayerStat_Changed.IsBound() == true)
		OnPlayerStat_Changed.Execute();
}

void AD2Player::SetMana(float value)
{
	Super::SetMana(value);

	if(OnPlayerStat_Changed.IsBound() == true)
		OnPlayerStat_Changed.Execute();
}

void AD2Player::SetMaxMana(float value)
{
	Super::SetMaxMana(value);

	if(OnPlayerStat_Changed.IsBound() == true)
		OnPlayerStat_Changed.Execute();
}
