// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner_cada_cierto_tiempo.h"

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
	
}

// Called every frame
void ASpawner_cada_cierto_tiempo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

