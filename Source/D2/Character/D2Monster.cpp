// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/D2Monster.h"

AD2Monster::AD2Monster()
{
	Super::BeginPlay();
	UnHighlightActor();
}

void AD2Monster::BeginPlay()
{
	Super::BeginPlay();

	SetHealth(20);
	SetMaxHealth(20);
	SetAttack(1);
}

void AD2Monster::HighlightActor()
{
	bHighlighted = true;
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250);
	Weapon->SetRenderCustomDepth(true);
}

void AD2Monster::UnHighlightActor()
{
	bHighlighted = false;
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

