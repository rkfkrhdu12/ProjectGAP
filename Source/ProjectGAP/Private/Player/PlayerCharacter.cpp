// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCharacter.h"

APlayerCharacter::APlayerCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rate for input
	TurnRateGamepad = 50.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	CharacterMovement = GetCharacterMovement();
	if (!CharacterMovement) return PrintString("CharacterMovement is Null");
	CharacterMovement->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	CharacterMovement->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	CharacterMovement->JumpZVelocity = 700.f;
	CharacterMovement->AirControl = 0.35f;
	CharacterMovement->MaxWalkSpeed = 500.f;
	CharacterMovement->MinAnalogWalkSpeed = 20.f;
	CharacterMovement->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	if (!CameraArm) return PrintString("CameraArm is Null");
	CameraArm->SetupAttachment(RootComponent);
	CameraArm->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraArm->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(CameraArm, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	MainCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}
