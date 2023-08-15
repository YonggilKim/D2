// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/D2CharacterBase.h"
#include "D2Player.generated.h"

DECLARE_DELEGATE(FDele_Stat_Changed); 


/**
 * 
 */
UCLASS()
class D2_API AD2Player : public AD2CharacterBase
{
	GENERATED_BODY()

public:
	AD2Player();
	void SetMaxHealth(float value) override;
	void SetHealth(float value) override;
	void SetMana(float value) override;
	void SetMaxMana(float value) override;

	FDele_Stat_Changed OnPlayerStat_Changed;
	
protected:
	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<class UCameraComponent> FollowCamera;
};
