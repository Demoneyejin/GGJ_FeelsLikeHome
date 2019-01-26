// Fill out your copyright notice in the Description page of Project Settings.

#include "SideScrollerPawn.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ASideScrollerPawn::ASideScrollerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FlipbookComp = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook Comp"));
	FlipbookComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ASideScrollerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASideScrollerPawn::MoveRight(float Axis)
{
	//GetMovementComponent()->AddInputVector(FVector(1.0, 0.0, 0.0)* Axis);
}

void ASideScrollerPawn::Pawn_Jump()
{
	//GetMovementComponent()->
}

// Called every frame
void ASideScrollerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASideScrollerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASideScrollerPawn::Pawn_Jump);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASideScrollerPawn::MoveRight);

}

