// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "GAS/Attributes/GAS_AliveObjectAttributeSet.h"
#include "GAS_CharacterAttributeSet.generated.h"


/**
 * CharacterAttributeSet holds properties related to all kind of Characters 
 */
UCLASS()
class CHIPSPROJECT_API UGAS_CharacterAttributeSet : public UGAS_AliveObjectAttributeSet
{
	GENERATED_BODY()

public:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/* Defining Character Attributes & Replication Functions for each one */
	

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UGAS_CharacterAttributeSet, Mana);

	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);
	

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ManaRegeneration)
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UGAS_CharacterAttributeSet, ManaRegeneration);

	UFUNCTION()
	virtual void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Power)
	FGameplayAttributeData Power;
	ATTRIBUTE_ACCESSORS(UGAS_CharacterAttributeSet, Power);

	UFUNCTION()
	virtual void OnRep_Power(const FGameplayAttributeData& OldPower);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AttackSpeed)
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS(UGAS_CharacterAttributeSet, AttackSpeed);

	UFUNCTION()
	virtual void OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed);

	
};
