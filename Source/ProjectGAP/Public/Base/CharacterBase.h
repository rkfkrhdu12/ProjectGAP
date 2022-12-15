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
	// Sets default values for this character's properties
	ACharacterBase();
	~ACharacterBase();

	virtual void DefaultInitialize(); // �����ڿ� ������ ����
	virtual void Spawn(); // ���� ��ų�� �ʿ��� > �����Ҷ����� ������ �ϴ°͵� ����
	virtual void Enable(); // ���� �� �������� ������ ����
	virtual void Start(); // �ൿ ����

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
