// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimationComponent.generated.h"

class ACharacter;
class UCharacterMovementComponent;

UENUM(BlueprintType)
enum class EAnimationState : uint8
{
	Idle,
	Moving,
	Jumping
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GGJ_FEELSLIKEHOME_API UAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

	

public:	
	// Sets default values for this component's properties
	UAnimationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	ACharacter* ownedPawn;
	UCharacterMovementComponent* MoveComp;

	UPROPERTY()
	EAnimationState AnimState;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Animation State")
	EAnimationState GetAnimationState();
		
};
