// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Attributes/GAS_CharacterAttributeSet.h"
#include "GAS_PlayerAttributeSet.generated.h"

/**
 * PlayerAttributeSet holds properties related to all kind of Players 
 */
UCLASS()
class CHIPSPROJECT_API UGAS_PlayerAttributeSet : public UGAS_CharacterAttributeSet
{
	GENERATED_BODY()

public:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/* Defining Player Attributes & Replication Functions for each one */
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Magnet)
	FGameplayAttributeData Magnet;
	ATTRIBUTE_ACCESSORS(UGAS_PlayerAttributeSet, Magnet);

	UFUNCTION()
	virtual void OnRep_Magnet(const FGameplayAttributeData& OldMagnet);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Greed)
	FGameplayAttributeData Greed;
	ATTRIBUTE_ACCESSORS(UGAS_PlayerAttributeSet, Greed);

	UFUNCTION()
	virtual void OnRep_Greed(const FGameplayAttributeData& OldGreed);
};
