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
	// Sets default values for this character's properties
	ACharacterBase();
	~ACharacterBase();

	virtual void DefaultInitialize(); // 생성자용 데이터 정의
	virtual void Spawn(); // 스폰 시킬때 필요한 > 스폰할때부터 보여야 하는것들 정의
	virtual void Enable(); // 스폰 후 실질적인 동작을 실행
	virtual void Start(); // 행동 시작

	virtual void End();
	virtual void Disable();
	virtual void Despawn();
	virtual void Delete();

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
