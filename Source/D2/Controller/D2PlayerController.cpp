#include "Controller/D2PlayerController.h"
#include <ObjectArray.h>
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Actor/D2Projectile.h"
#include "Interfaces/EnemyInterface.h"
#include "UI/HUD/D2HUD.h"
#include "Kismet/GameplayStatics.h"

AD2PlayerController::AD2PlayerController()
{
	
}

void AD2PlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(D2Context);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
		Subsystem->AddMappingContext(D2Context, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

	//HUD INit
	if(AD2PlayerController* D2PlayerController =  Cast<AD2PlayerController>(this))
	{
		if(AD2HUD*  hud = Cast<AD2HUD>(D2PlayerController->GetHUD()))
		{

			ACharacter* ch = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
			AD2Player* player = Cast<AD2Player>(ch);
			player->SetHealth(30);
			player->SetMaxHealth(100);
			player->SetMana(20);
			player->SetMaxMana(50);
			player->SetAttack(15);			
			hud->InitOverlay(D2PlayerController,player);
		}
	}
}

void AD2PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent =  CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AD2PlayerController::Move);
	EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Completed, this, &AD2PlayerController::Attack);

}

void AD2PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	TickCursorTrace();
}

void AD2PlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D InputAxisVector = Value.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}



void AD2PlayerController::TickCursorTrace()
{
	FHitResult CursorHit;

	if (GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, OUT CursorHit) == false)
		return;

	IEnemyInterface* LocalTargetActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	if (LocalTargetActor == nullptr)
	{
		// 원래 있었는데, 없어짐
		if (TargetActor)
		{
			TargetActor->UnHighlightActor();
		}
	}
	else
	{
		if (TargetActor)
		{
			// 원래 있었는데 다른 애였음
			if (TargetActor != LocalTargetActor)
			{
				TargetActor->UnHighlightActor();
				LocalTargetActor->HighlightActor();
			}
			
			// 동일한 애면 무시
		}
		else
		{
			// 원래 없었고 새로 주시
			LocalTargetActor->HighlightActor();
		}
	}

	// 저장
	TargetActor = LocalTargetActor;
	Target = Cast<AD2CharacterBase>(CursorHit.GetActor());
}


