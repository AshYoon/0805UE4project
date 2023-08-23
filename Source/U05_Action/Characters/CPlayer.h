#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CStateComponent.h"
#include "Characters/ICharacter.h"
#include "GenericTeamAgentInterface.h"
#include "CPlayer.generated.h"

// state���� enum�� �ִ� , enum�� ���漱�� �̾ȵȴ� 
// enum���� �����ؾ��ϴϱ� ����� �־�����Ѵ� 
// ��ӱ��� �߰��ϴ� ��� Check 
UCLASS()
class U05_ACTION_API ACPlayer : public ACharacter,public IICharacter , public IGenericTeamAgentInterface
{
	
	GENERATED_BODY()




private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UCUserWidget_ActionList> ActionListClass;


public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "AI")
		int32 ID = 255;


	//virtual FGenericTeamId GetGenericTeamId() const override { return TeamID; } //team id ���� 
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamID; }

private:

	// �ʿ��Ѱ� ������Ʈ�� �߰��ϰ� �� �߰��Ѵ���� Player 

	UPROPERTY(VisibleDefaultsOnly)
		class UCActionComponent* Action;

	// Ÿ�� ������� 
	UPROPERTY(VisibleDefaultsOnly)
		class UCTargetComponent* Target;



	UPROPERTY(VisibleDefaultsOnly)
		class UCMontagesComponent* Montages;

	UPROPERTY(VisibleDefaultsOnly)
		class UCFeetComponent* Feet;


	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent* Camera;


	

	UPROPERTY(VisibleDefaultsOnly)
		class UCOptionComponent* Option;

	UPROPERTY(VisibleDefaultsOnly)
		class UCStatusComponent* Status;

	UPROPERTY(VisibleDefaultsOnly)
		class UCStateComponent* State;

public:
	FORCEINLINE class UCUserWidget_ActionList* GetActionList() { return ActionList; }



public:

	ACPlayer();

protected:

	virtual void BeginPlay() override;


	FGenericTeamId TeamID; //TeamID���� 
private:
	//Axis
	void OnMoveForward(float InAxis);
	void OnMoveRight(float InAxis);
	void OnHorizontalLook(float InAxis);
	void OnVerticalLook(float InAxis);
	void OnZoom(float InAxis);
	

private:
	void OnAvoid();


public:	

	virtual void Tick(float DeltaTime) override;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UFUNCTION()
		void OnStateTypeChanged(EStateType InPrevType, EStateType InNewType);
	// add dynamic���� 
private:
	//Actions 
	void Begin_Roll();
	void Begin_Backstep();

public:
	void End_Roll();
	void End_Backstep();
private:
	UFUNCTION()
		void OnOneHand();
	UFUNCTION()
	void OnTwoHand();
	UFUNCTION()
	void OnFist();
	UFUNCTION()
	void OnWarp();
	UFUNCTION()
	void OnFireStorm();
	UFUNCTION()
	void OnIceBall();

	void OnAim();
	void OffAim();
	void OnDoAction();
	void OnViewActionList();
	void OffViewActionList();
	void InterActive();


	


	void OnTarget();
	void OnTargetLeft();
	void OnTargetRight();

public:
	virtual void ChangeColor(FLinearColor InColor) override;
	


private:
	class UMaterialInstanceDynamic* BodyMaterial;
	class UMaterialInstanceDynamic* LogoMaterial;
	// ���� ������ ���ۉ����� �ٲ��ָ�ȴ� , Player��� �������� �˷��ټ��ִ� 
	// TypeColor�� �غ����� 
private:
		class UCUserWidget_ActionList* ActionList;


};
