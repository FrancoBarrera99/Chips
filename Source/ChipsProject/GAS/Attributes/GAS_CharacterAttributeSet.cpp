// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Attributes/GAS_CharacterAttributeSet.h"
#include "Net/UnrealNetwork.h"

void UGAS_CharacterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_CharacterAttributeSet, Health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_CharacterAttributeSet, Mana, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_CharacterAttributeSet, HealthRegeneration, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_CharacterAttributeSet, ManaRegeneration, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_CharacterAttributeSet, Power, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_CharacterAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always)

}

void UGAS_CharacterAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_CharacterAttributeSet, Health, OldHealth);
}

void UGAS_CharacterAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_CharacterAttributeSet, Mana, OldMana);
}

void UGAS_CharacterAttributeSet::OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_CharacterAttributeSet, HealthRegeneration, OldHealthRegeneration);
}

void UGAS_CharacterAttributeSet::OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_CharacterAttributeSet, ManaRegeneration, OldManaRegeneration);
}

void UGAS_CharacterAttributeSet::OnRep_Power(const FGameplayAttributeData& OldPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_CharacterAttributeSet, Power, OldPower);
}

void UGAS_CharacterAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_CharacterAttributeSet, AttackSpeed, OldAttackSpeed);
}

