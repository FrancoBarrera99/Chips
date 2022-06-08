// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Character/GAS_Character.h"

#include "GAS/GAS_Character_PlayerState.h"

// Sets default values
AGAS_Character::AGAS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
}

// Called when the game starts or when spawned
void AGAS_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGAS_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if(!GetPlayerState() || GetLocalRole() != ROLE_Authority)
	{
		return;
	}

	AGAS_Character_PlayerState* GASCharacterPlayerState = Cast<AGAS_Character_PlayerState>(GetPlayerState());

	if(GASCharacterPlayerState)
	{
		AbilitySystemComponent = Cast<AGAS_Character_PlayerState>(GetPlayerState())->AbilitySystemComponent;

		/* Set Owner and Avatar Actor for ASC */
		AbilitySystemComponent->InitAbilityActorInfo(GetPlayerState(), this);
	}
}

void AGAS_Character::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	AGAS_Character_PlayerState* GASCharacterPlayerState = Cast<AGAS_Character_PlayerState>(GetPlayerState());

	if(GASCharacterPlayerState)
	{
		AbilitySystemComponent = Cast<AGAS_Character_PlayerState>(GetPlayerState())->AbilitySystemComponent;

		/* Set Owner and Avatar Actor for ASC */
		AbilitySystemComponent->InitAbilityActorInfo(GetPlayerState(), this);
	}
}

// Called every frame
void AGAS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGAS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

