// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterEvent);

/*
// Class()
OnInitEvent �������� Ȱ��ȭ ��ü���� ������ Init
// BeginPlay()
OnSpawnEvent ���ӿ� �����ϴ� ���ͷ� Ȱ��ȭ �������μ��� ������ Init
OnEnableEvent �������� ����(�ִϸ��̼�, BT��)�� ���� ������ Init
OnStartEvent ���� �����͵��� Start
OnUpdateEvent ���� �����͵��� Update
OnEndEvent ���� �����͵��� End
OnDsiableEvent ���������� ����
OnDespawnEvent ������ ���Ͱ� �ƴ� ��ó�� ��Ȱ��ȭ(Pooling System Collect)
OnDeleteEvent ���������� ���� ���� delete Data;
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
