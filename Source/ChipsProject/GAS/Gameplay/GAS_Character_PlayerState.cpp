// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Gameplay/GAS_Character_PlayerState.h"
#include "GAS/Attributes/GAS_CharacterAttributeSet.h"

AGAS_Character_PlayerState::AGAS_Character_PlayerState()
{
	/* Create ASC */
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	/* Create CharacterAttributeSet */
	AttributeSet = CreateDefaultSubobject<UGAS_CharacterAttributeSet>("AttributeSet");
}

void AGAS_Character_PlayerState::GrantAbility(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, int32 InputCode)
{
	if(AbilitySystemComponent && HasAuthority() && IsValid(AbilityClass))
	{
		UGameplayAbility* Ability = AbilityClass->GetDefaultObject<UGameplayAbility>();

		if(IsValid(Ability))
		{
			FGameplayAbilitySpec AbilitySpec (
			Ability,
			Level,
			InputCode
			);
		
			AbilitySystemComponent->GiveAbility(AbilitySpec);
		}
	}
}

void AGAS_Character_PlayerState::ActivateAbility(int32 InputCode)
{
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->AbilityLocalInputPressed(InputCode);
	}
}
