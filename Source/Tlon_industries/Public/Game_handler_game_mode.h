// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Game_handler_game_mode.generated.h"

/**
 * 
 */
UCLASS()
class TLON_INDUSTRIES_API AGame_handler_game_mode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int cantidad_de_enemigos_a_instanciar_por_Seconds{ 1 };
	
};
