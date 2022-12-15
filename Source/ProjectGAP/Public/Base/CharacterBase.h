// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterEvent);

/*
// Class()
OnInitEvent 실질적인 활성화 자체적인 데이터 Init
// BeginPlay()
OnSpawnEvent 게임에 존재하는 액터로 활성화 수명으로서의 데이터 Init
OnEnableEvent 렌더링을 위한(애니메이션, BT등)을 위한 데이터 Init
OnStartEvent 현재 데이터들을 Start
OnUpdateEvent 현재 데이터들을 Update
OnEndEvent 현재 데이터들을 End
OnDsiableEvent 렌더링관련 종료
OnDespawnEvent 게임의 액터가 아닌 것처럼 비활성화(Pooling System Collect)
OnDeleteEvent 실질적으로 삭제 직전 delete Data;
*/

UCLASS()
class PROJECTGAP_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()
public:
	ACharacterBase();
	~ACharacterBase();

	virtual bool Initialize();
	virtual bool Spawn();
	virtual bool Enable();
	virtual bool Start();

	virtual bool End();
	virtual bool Disable();
	virtual bool Despawn();
	virtual bool Delete();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public: // Debug
	bool PrintString(FString log, bool returnValue = true) const;
};
