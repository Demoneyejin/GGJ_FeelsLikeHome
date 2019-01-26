// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SideScrollerPawn.generated.h"


class UPaperFlipbookComponent;
class UAnimationComponent;

UCLASS()
class GGJ_FEELSLIKEHOME_API ASideScrollerPawn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASideScrollerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Component")
	UPaperFlipbookComponent* FlipbookComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Component")
	UAnimationComponent* AnimStateComponent;

	void MoveRight(float Axis);
	void Pawn_Jump();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
