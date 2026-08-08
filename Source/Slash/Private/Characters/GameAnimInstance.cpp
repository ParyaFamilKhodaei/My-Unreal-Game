// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GameAnimInstance.h"
#include "Characters/GameCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UGameAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	GameCharacter = Cast<AGameCharacter>(TryGetPawnOwner());
	if (GameCharacter)
	{
		GameCharacterMovement = GameCharacter->GetCharacterMovement();
	}
}

void UGameAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (GameCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(GameCharacterMovement->Velocity);
		IsFalling = GameCharacterMovement->IsFalling();
	    CharacterState = GameCharacter->GetCharacterState();
	}
}
