// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/CharacterBase.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGAP_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()
public:
	APlayerCharacter();

	virtual bool Initialize() override;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraArm = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* MainCamera = nullptr;

};
