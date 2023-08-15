


#include "UI/Controller/OverlayWidgetController.h"

#include "Character/D2CharacterBase.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	OnHealthChanged.Broadcast(Player->GetHealth());
	OnMaxHealthChanged.Broadcast(Player->GetMaxHealth());
	OnManaChanged.Broadcast(Player->GetMana());
	OnMaxManaChanged.Broadcast(Player->GetMaxMana());

	//Bind
	Player->OnPlayerStat_Changed.BindUFunction(this, FName("HandlePlayerStatChanged"));
}

void UOverlayWidgetController::HandlePlayerStatChanged()
{
	OnHealthChanged.Broadcast(Player->GetHealth());
	OnMaxHealthChanged.Broadcast(Player->GetMaxHealth());
	OnManaChanged.Broadcast(Player->GetMana());
	OnMaxManaChanged.Broadcast(Player->GetMaxMana());
}
