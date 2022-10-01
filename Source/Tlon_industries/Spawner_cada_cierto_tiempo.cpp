// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner_cada_cierto_tiempo.h"



//gamemode
#include <Kismet/GameplayStatics.h>
#include <Engine/World.h>
//#include "Engine/Engine.h"
//#include "TimerManager.h"

#include "Public/Game_handler_game_mode.h"

#include "Kismet/KismetMathLibrary.h"



//////////////



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
	
	spawn_alien();

	if (GetWorld() == nullptr) return;
	GetWorld()->GetTimerManager().SetTimer(timer_handle_search_game_mode, this, &ASpawner_cada_cierto_tiempo::OnTimerOut_search_game_mode, 0.1, false);
	
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
	if (game_mode == nullptr) return;

	cant_a_instanciar = game_mode->cantidad_de_enemigos_a_instanciar_por_Seconds;


	for (int i = 0; i < cant_a_instanciar; i++)//instancio segun cantidad que recibo desde UI
	{
		spawn_alien();
	}
}


//intancia el alien
void ASpawner_cada_cierto_tiempo::spawn_alien()
{
	if (GetWorld() == nullptr) return;
	// Don't forget to include World.h to use methods inside UWorld Class
	FActorSpawnParameters spawn_params{};
	spawn_params.Owner = nullptr; // Specify owner actor for this new actor if you need one.
	spawn_params.Instigator = nullptr; // Specify instigator pawn for this new actor if you need one
	spawn_params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FTransform new_actor_transform = FTransform::Identity; // Identity Matrix if you need the default transformation.

	
	//rango aleatorio para que no se pisen
	float new_minimum_x = GetActorLocation().X + minimum_x;
	float new_maximum_x = GetActorLocation().X - maximum_x;
	float randon_value_x = UKismetMathLibrary::RandomFloatInRange(new_minimum_x, new_maximum_x);

	float new_minimum_y = GetActorLocation().Y + minimum_y;
	float new_maximum_y = GetActorLocation().Y - maximum_y;
	float randon_value_y = UKismetMathLibrary::RandomFloatInRange(new_minimum_y, new_maximum_y);

	new_actor_transform.SetLocation(FVector(
		randon_value_x,
		randon_value_y,
		GetActorLocation().Z
	));

	// Spawn Actor return a Pointer to new Actor
	GetWorld()->SpawnActor<AActor>(alien, new_actor_transform, spawn_params);
}




//get game mode after 1 second
void ASpawner_cada_cierto_tiempo::OnTimerOut_search_game_mode()
{
	//game_mode = UGameplayStatics::GetGameMode( GetWorld() );
	if (GetWorld()->GetAuthGameMode() == nullptr)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("No se encontro el GameMode"));
		return;
	}

	game_mode = Cast< AGame_handler_game_mode>( GetWorld()->GetAuthGameMode() );
}

