// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/D2Monster.h"

#include "UI/Widget/D2UserWidget.h"

AD2Monster::AD2Monster()
{
	HealthBar = CreateDefaultSubobject<UWidgetComponent>("HealthBar");
	HealthBar->SetupAttachment(GetRootComponent());
}

void AD2Monster::BeginPlay()
{
	Super::BeginPlay();
	UnHighlightActor();

	SetHealth(20);
	SetMaxHealth(20);
	SetAttack(1);

	if (UD2UserWidget* D2Widget = Cast<UD2UserWidget>(HealthBar->GetUserWidgetObject()))
	{
		D2Widget->SetWidgetController(this);
	}
	OnMaxHealthChanged.Broadcast(GetMaxHealth());
	OnHealthChanged.Broadcast(GetHealth());

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

void AD2Monster::SetMaxHealth(float value)
{
	Super::SetMaxHealth(value);
	OnMaxHealthChanged.Broadcast(value);

}

void AD2Monster::SetHealth(float value)
{
	Super::SetHealth(value);
	OnHealthChanged.Broadcast(value);

}

void AD2Monster::SetMana(float value)
{
	Super::SetMana(value);
}

void AD2Monster::SetMaxMana(float value)
{
	Super::SetMaxMana(value);
}

