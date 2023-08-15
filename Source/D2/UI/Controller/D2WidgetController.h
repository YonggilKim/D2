

#pragma once

#include "CoreMinimal.h"
#include "Character/D2Player.h"
#include "UObject/NoExportTypes.h"
#include "D2WidgetController.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams(){}
	// FWidgetControllerParams(APlayerController* PC)
	// 	:PlayerController(PC)
	// {}
	FWidgetControllerParams(APlayerController* PC, AD2Player* P)
		: PlayerController(PC), Player(P)
	{}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<AD2Player> Player;
};

class APlayerController;
UCLASS()
class D2_API UD2WidgetController : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& params);

	UFUNCTION(BlueprintCallable)
	virtual void BroadcastInitialValues() {} 
protected:
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<AD2Player> Player;
};
