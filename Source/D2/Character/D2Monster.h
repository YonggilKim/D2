// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/D2CharacterBase.h"
#include "Interfaces/EnemyInterface.h"
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


};
