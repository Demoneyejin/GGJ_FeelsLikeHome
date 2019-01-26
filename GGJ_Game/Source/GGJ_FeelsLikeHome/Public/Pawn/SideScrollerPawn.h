// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SideScrollerPawn.generated.h"


class UPaperFlipbookComponent;
class UAnimationComponent;
class UArrowComponent;

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

	//Use this for aiming.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component")
	UArrowComponent* AimingArrow;

	void MoveRight(float Axis);
	void Pawn_Jump();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
