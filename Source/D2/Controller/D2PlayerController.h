

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Actor/D2Projectile.h"
#include "Character/D2CharacterBase.h"
#include "GameFramework/PlayerController.h"
#include "D2PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class D2_API AD2PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AD2PlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;

	void Move(const struct FInputActionValue& Value);
	UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
	void Attack(const struct FInputActionValue& Value);

private:
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputMappingContext> D2Context;
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputAction> AttackAction;
	void TickCursorTrace();
	IEnemyInterface* TargetActor;
public:
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<AD2CharacterBase> Target;

};
