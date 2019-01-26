// Fill out your copyright notice in the Description page of Project Settings.

#include "SideScrollerPawn.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "AnimationComponent.h"
#include "Components/ArrowComponent.h"

// Sets default values
ASideScrollerPawn::ASideScrollerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FlipbookComp = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook Comp"));
	FlipbookComp->SetupAttachment(RootComponent);

	AimingArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Aiming Arrow Component"));
	AimingArrow->SetupAttachment(FlipbookComp);

	AnimStateComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("Animation Component"));
}

// Called when the game starts or when spawned
void ASideScrollerPawn::BeginPlay()
{
	Super::BeginPlay();
	//incase we want to check if we're at the apex of the jump
	GetCharacterMovement()->bNotifyApex = true;
}
	

void ASideScrollerPawn::MoveRight(float Axis)
{

	if (Axis < 0)
	{
		if (FMath::Abs(FlipbookComp->GetRelativeTransform().GetRotation().Rotator().Yaw) != 180)
			FlipbookComp->SetRelativeRotation(FRotator(0.0, 180, 0.0));
	}
	if (Axis > 0)
	{
		if (FMath::Abs(FlipbookComp->GetRelativeTransform().GetRotation().Rotator().Yaw) != 0)
			FlipbookComp->SetRelativeRotation(FRotator(0.0, 0.0, 0.0));
	}

	GetMovementComponent()->AddInputVector(FVector(1.0, 0.0, 0.0)* Axis);
}

void ASideScrollerPawn::Pawn_Jump()
{
	Jump();
	//incase we want to check if we're at the apex of the jump
	GetCharacterMovement()->bNotifyApex = true;
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

