#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CAIController.generated.h"

UCLASS()
class U05_ACTION_API ACAIController : public AAIController
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		float MeleeActionRange = 150;

	UPROPERTY(EditAnywhere)
		bool bDrawDebug = true;

	UPROPERTY(EditAnywhere)
		float AdjustCircleHeight = 50;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UAIPerceptionComponent* Perception;

	UPROPERTY(VisibleDefaultsOnly)
		class UCBehaviorComponent* Behavior;

public:
	FORCEINLINE float GetMeleeActionRange() { return MeleeActionRange; }

public:
	ACAIController();

	float GetSightRadius();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

private:
	UFUNCTION()
		void OnPerceptionUpdated(const TArray<AActor*>& UpdateActors);

private:
	class ACEnemy_AI* OwnerEnemy;
	class UAISenseConfig_Sight* Sight; // 시야만 사용함 

};
