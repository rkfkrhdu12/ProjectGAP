// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/CharacterBase.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultInitialize();
}

ACharacterBase::~ACharacterBase()
{
	Delete();
}

void ACharacterBase::DefaultInitialize()
{

}

void ACharacterBase::Spawn()
{

}

void ACharacterBase::Enable()
{

}

void ACharacterBase::Start()
{

}

void ACharacterBase::End()
{

}

void ACharacterBase::Disable()
{

}

void ACharacterBase::Despawn()
{

}

void ACharacterBase::Delete()
{

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

bool ACharacterBase::PrintString(FString log, bool returnValue = true) const
{
	UKismetSystemLibrary::PrintString(GetWorld(), FString::Printf(GetName() + " : " + log));

	return returnValue;
}

