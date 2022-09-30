// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner_cada_cierto_tiempo.h"

#include <Engine/World.h>
#include "TimerManager.h"


// Sets default values
ASpawner_cada_cierto_tiempo::ASpawner_cada_cierto_tiempo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner_cada_cierto_tiempo::BeginPlay()
{
	Super::BeginPlay();
	


	if (GetWorld() == nullptr) return;
	GetWorld()->GetTimerManager().SetTimer(timer_handle, this, &ASpawner_cada_cierto_tiempo::OnTimerOut_spawn_alien, timer_to_end, repeat_timer);

}

// Called every frame
void ASpawner_cada_cierto_tiempo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawner_cada_cierto_tiempo::OnTimerOut_spawn_alien()
{
	if (GetWorld() == nullptr) return;
	for (int i = 0; i < cant_a_instanciar; i++)
	{
		spawn_alien();
	}
}



void ASpawner_cada_cierto_tiempo::spawn_alien()
{
	// Don't forget to include World.h to use methods inside UWorld Class
	FActorSpawnParameters spawn_params{};
	spawn_params.Owner = nullptr; // Specify owner actor for this new actor if you need one.
	spawn_params.Instigator = nullptr; // Specify instigator pawn for this new actor if you need one
	spawn_params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FTransform new_actor_transform = FTransform::Identity; // Identity Matrix if you need the default transformation.

	new_actor_transform.SetLocation(GetActorLocation());

	// Spawn Actor return a Pointer to new Actor
	GetWorld()->SpawnActor<AActor>(alien, new_actor_transform, spawn_params);
}

