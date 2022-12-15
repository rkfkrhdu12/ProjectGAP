// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/CharacterBase.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACharacterBase::ACharacterBase() : ACharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	Initialize();
}

ACharacterBase::~ACharacterBase()
{
	Delete();
}

bool ACharacterBase::Initialize()
{
	return true;
}

bool ACharacterBase::Spawn()
{
	return true;
}

bool ACharacterBase::Enable()
{
	return true;
}

bool ACharacterBase::Start()
{
	return true;
}

bool ACharacterBase::End()
{
	return true;
}

bool ACharacterBase::Disable()
{
	return true;
}

bool ACharacterBase::Despawn()
{
	return true;
}

bool ACharacterBase::Delete()
{
	return true;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	Spawn();
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ACharacterBase::PrintString(FString log, bool returnValue /*= true*/) const
{
	FString str = FString::Printf(TEXT("GAPLOG %s : %s"), *GetName(), *log);
	UKismetSystemLibrary::PrintString(GetWorld(), str);

	return returnValue;
}

