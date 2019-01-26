// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimationComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UAnimationComponent::UAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAnimationComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
	ownedPawn = Cast<ACharacter>(GetOwner());
	if (ownedPawn)
	{
		MoveComp =	Cast<UCharacterMovementComponent>(ownedPawn->GetMovementComponent());
	}
}


// Called every frame
/**
	Creating an animation changing component which changes the animation state based on the data from the characters movement component
*/
void UAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (MoveComp->Velocity.Size() > 0 && (MoveComp->IsFalling() == false))
	{
		AnimState = EAnimationState::Moving;
	}
	else if (MoveComp->IsFalling())
	{
		AnimState = EAnimationState::Jumping;
	}
	else
	{
		AnimState = EAnimationState::Idle;
	}
}

EAnimationState UAnimationComponent::GetAnimationState()
{
	return AnimState;
}