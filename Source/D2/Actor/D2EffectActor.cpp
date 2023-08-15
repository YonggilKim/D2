


#include "Actor/D2EffectActor.h"

#include "Character/D2CharacterBase.h"

// Sets default values
AD2EffectActor::AD2EffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
	
}

// Called when the game starts or when spawned
void AD2EffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AD2EffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AD2EffectActor::EndOVerlap);
}

void AD2EffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(AD2CharacterBase* base =  Cast<AD2CharacterBase>(OtherActor))
	{
		base->SetHealth(base->GetHealth()+10);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("on actor begin overlap works!")));

		Destroy();
	}else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Casting Failed!")));

	}
}

void AD2EffectActor::EndOVerlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AD2EffectActor::ApplyEffectToTarget(AActor* TargetActor)
{
}


