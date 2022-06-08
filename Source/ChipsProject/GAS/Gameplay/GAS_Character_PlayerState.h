// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/PlayerState.h"
#include "GAS_Character_PlayerState.generated.h"

/**
 * This player state is created to hold the ASC and the AttributeSet for a Character
 * It could be use both for AI Controlled or Player Controlled Characters
 */
UCLASS()
class CHIPSPROJECT_API AGAS_Character_PlayerState : public APlayerState
{
	GENERATED_BODY()

public:

	AGAS_Character_PlayerState();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class UGAS_CharacterAttributeSet* AttributeSet;

	/** ASC getter */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent()
	{
		return AbilitySystemComponent;
	}

	/** Called to grant a new Ability to the ASC (Server) */
	UFUNCTION(BlueprintCallable, Category="Abilities")
	void GrantAbility(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, int32 InputCode);

	/** Called to use a registered Ability */
	UFUNCTION(BlueprintCallable, Category="Abilities")
	void ActivateAbility(int32 InputCode);
};
