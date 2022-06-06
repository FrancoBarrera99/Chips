// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GAS_CharacterPlayerState.h"

#include "Attributes/GAS_CharacterAttributeSet.h"

AGAS_CharacterPlayerState::AGAS_CharacterPlayerState()
{
	/* Create ASC */
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	/* Create AttributeSet */
	AttributeSet = CreateDefaultSubobject<UGAS_CharacterAttributeSet>("AttributeSet");
}

void AGAS_CharacterPlayerState::GrantAbility(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, int32 InputCode)
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

void AGAS_CharacterPlayerState::ActivateAbility(int32 InputCode)
{
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->AbilityLocalInputPressed(InputCode);
	}
}
