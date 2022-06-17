// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Attributes/GAS_PlayerAttributeSet.h"

#include "Net/UnrealNetwork.h"


void UGAS_PlayerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_PlayerAttributeSet, Magnet, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_PlayerAttributeSet, Greed, COND_None, REPNOTIFY_Always)
	
}

void UGAS_PlayerAttributeSet::OnRep_Magnet(const FGameplayAttributeData& OldMagnet)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_PlayerAttributeSet, Magnet, OldMagnet)
}

void UGAS_PlayerAttributeSet::OnRep_Greed(const FGameplayAttributeData& OldGreed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_PlayerAttributeSet, Greed, OldGreed)
}