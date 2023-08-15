

#pragma once

#include "CoreMinimal.h"
#include "SNodePanel.h"
#include "GameFramework/HUD.h"
#include "UI/Controller/OverlayWidgetController.h"
#include "D2HUD.generated.h"

/**
 * 
 */

class UD2UserWidget;
class UOverlayWidgetController;

struct  FWidgetControllerParams;

UCLASS()
class D2_API AD2HUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual  void BeginPlay() override;


public:
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& params);
	void InitOverlay(APlayerController* PC, AD2Player* Player);
	
	UPROPERTY()
	TObjectPtr<UD2UserWidget> OverlayWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UD2UserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
