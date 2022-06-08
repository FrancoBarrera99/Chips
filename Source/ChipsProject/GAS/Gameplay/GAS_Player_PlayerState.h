// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS_Character_PlayerState.h"
#include "GAS_Player_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class CHIPSPROJECT_API AGAS_Player_PlayerState : public AGAS_Character_PlayerState
{
	GENERATED_BODY()

public:

	/* Replace CharacterAttributeSet for PlayerAttributeSet */
	AGAS_Player_PlayerState(const FObjectInitializer& ObjectInitializer);
	
};
