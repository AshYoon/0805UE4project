#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CStateComponent.h"
#include "Characters/ICharacter.h"
#include "GenericTeamAgentInterface.h"
#include "CPlayer.generated.h"

// state에는 enum이 있다 , enum은 전방선언 이안된다 
// enum문에 접근해야하니깐 헤더에 넣어줘야한다 
// 상속구조 추가하는 방법 Check 
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


	//virtual FGenericTeamId GetGenericTeamId() const override { return TeamID; } //team id 세팅 
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamID; }

private:

	// 필요한건 컴포넌트에 추가하고 그 추가한대상이 Player 

	UPROPERTY(VisibleDefaultsOnly)
		class UCActionComponent* Action;

	// 타겟 잡기위한 
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


	FGenericTeamId TeamID; //TeamID변수 
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
	// add dynamic으로 
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
	// 색은 게임이 시작됬을때 바꿔주면된다 , Player가어떤 상태인지 알려줄수있는 
	// TypeColor를 해볼꺼다 
private:
		class UCUserWidget_ActionList* ActionList;


};
