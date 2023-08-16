


#include "Actor/D2Projectile.h"
#include "Character/D2CharacterBase.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AD2Projectile::AD2Projectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	SetRootComponent(Sphere);
	Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Sphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	Sphere->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	Sphere->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	Sphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	// Sphere->SetCollisionObjectType(ECC_Projectile);
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	ProjectileMovement->InitialSpeed = 550.f;
	ProjectileMovement->MaxSpeed = 550.f;
	ProjectileMovement->ProjectileGravityScale = 0.f;
	
	bReplicates = true;
}

// Called when the game starts or when spawned
void AD2Projectile::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(LifeSpan);

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AD2Projectile::OnSphereOverlap);

	// LoopingSoundComponent = UGameplayStatics::SpawnSoundAttached(LoopingSound, GetRootComponent());

}

void AD2Projectile::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation(), FRotator::ZeroRotator);
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, ImpactEffect, GetActorLocation());
	// LoopingSoundComponent->Stop();

	if(AD2CharacterBase* base = Cast<AD2CharacterBase>(OtherActor))
	{
		//base == monster
		base->SetHealth(base->GetHealth()-10);
	}
	
	bHit = true;
	Destroy();

//TODO 데미지 주기

}

void AD2Projectile::Destroyed()
{
	if (!bHit)
	{
		// UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation(), FRotator::ZeroRotator);
		// UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, ImpactEffect, GetActorLocation());
		// LoopingSoundComponent->Stop();
	}

	Super::Destroyed();
}
