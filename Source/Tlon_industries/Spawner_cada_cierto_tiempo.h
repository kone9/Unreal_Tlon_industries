// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner_cada_cierto_tiempo.generated.h"

UCLASS()
class TLON_INDUSTRIES_API ASpawner_cada_cierto_tiempo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner_cada_cierto_tiempo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<AActor> alien;

	FTimerHandle timer_handle;
	UPROPERTY(EditAnywhere)
	float timer_to_end{ 1.0f };
	UPROPERTY(EditAnywhere)
	bool repeat_timer{ true };

	UFUNCTION()
	void OnTimerOut_spawn_alien();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int cant_a_instanciar = 1;

public:
	void spawn_alien();



private:
	class AGame_handler_game_mode* game_mode{ nullptr };

public:
	FTimerHandle timer_handle_search_game_mode;

	UFUNCTION()
	void OnTimerOut_search_game_mode();






};
