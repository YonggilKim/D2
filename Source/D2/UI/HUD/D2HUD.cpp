#include "UI/HUD/D2HUD.h"

#include "Blueprint/UserWidget.h"
#include  "UI/Widget/D2UserWidget.h"
#include "UI/Controller/OverlayWidgetController.h"

void AD2HUD::BeginPlay()
{
	Super::BeginPlay();
}

UOverlayWidgetController* AD2HUD::GetOverlayWidgetController(const FWidgetControllerParams& params)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(params);
	}

	return OverlayWidgetController;
}

void AD2HUD::InitOverlay(APlayerController* PC, AD2Player* Player)
{
	check(OverlayWidgetClass);
	check(OverlayWidgetControllerClass);

	//Widget
	UD2UserWidget* Widget = CreateWidget<UD2UserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
	OverlayWidget = Widget;

	//WidgetContrller
	const FWidgetControllerParams params(PC, Player);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(params);
	OverlayWidget->SetWidgetController(WidgetController);

	WidgetController->BroadcastInitialValues();
}
