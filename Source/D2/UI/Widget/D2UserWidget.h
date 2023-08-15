

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "D2UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class D2_API UD2UserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();

protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
	
};
