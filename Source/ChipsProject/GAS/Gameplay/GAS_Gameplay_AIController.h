// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GAS_Gameplay_AIController.generated.h"

/**
 * An AIController that enables PlayerState on it to hold GAS attributes on AI Controlled Characters
 */
UCLASS()
class CHIPSPROJECT_API AGAS_Gameplay_AIController : public AAIController
{
	GENERATED_BODY()

public:

	AGAS_Gameplay_AIController();

};
