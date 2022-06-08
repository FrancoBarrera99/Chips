// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Gameplay/GAS_Player_PlayerState.h"
#include "GAS/Attributes/GAS_PlayerAttributeSet.h"

AGAS_Player_PlayerState::AGAS_Player_PlayerState(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer.SetDefaultSubobjectClass<UGAS_PlayerAttributeSet>("AttributeSet"))
{
	
}