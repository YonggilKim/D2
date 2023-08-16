// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/D2CharacterBase.h"
#include "Interfaces/EnemyInterface.h"
#include "UI/Controller/OverlayWidgetController.h"
#include "Components/WidgetComponent.h"

#include "D2Monster.generated.h"

/**
 * 
 */
UCLASS()
class D2_API AD2Monster : public AD2CharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AD2Monster();

	virtual void BeginPlay() override;
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

protected:
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

	void SetMaxHealth(float value) override;
	void SetHealth(float value) override;
	void SetMana(float value) override;
	void SetMaxMana(float value) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChangedSignature OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable)
	FOnMaxHealthChangedSignature OnMaxHealthChanged;
};
