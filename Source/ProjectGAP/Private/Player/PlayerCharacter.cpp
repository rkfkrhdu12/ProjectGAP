// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCharacter.h"

#include "Camera/CameraComponent.h"

#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"


APlayerCharacter::APlayerCharacter() : ACharacterBase()
{
}

bool APlayerCharacter::Initialize()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	if (!GetCharacterMovement()) return PrintString("CharacterMovement is Null");
	GetCharacterMovement()->bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	if (!GetCameraArm()) return PrintString("CameraArm is Null");
	GetCameraArm()->SetupAttachment(RootComponent);
	GetCameraArm()->TargetArmLength = 400.0f; 
	GetCameraArm()->bUsePawnControlRotation = true; 

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	if (!GetMainCamera()) return PrintString("MainCamera is Null");
	GetMainCamera()->SetupAttachment(GetCameraArm(), USpringArmComponent::SocketName);
	GetMainCamera()->bUsePawnControlRotation = false;

	return ACharacterBase::Initialize();
}
