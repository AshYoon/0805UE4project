// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CInventoryComponent.h"
#include "CEquipmentComponent.generated.h"



USTRUCT(BlueprintType)
struct F_EquipmentSlot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	F_Item Items;


	uint8 ActiveItemIndex;


	bool isHidden;


};

UENUM(BlueprintType)
enum class E_CombatType : uint8
{
	Unarmed,
	Melee,
	Range,
	Magic,

};

UENUM(BlueprintType)
enum class E_WeaponType : uint8
{
	None,
	Sword,
	Axe,
	Bow,
	Magic,

};




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class U05_ACTION_API UCEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCEquipmentComponent();

	void SetEquipment(F_Item* item);
	void RemoveEquipment(E_ItemType Type);



public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	TArray<F_EquipmentSlot> Equipment;




protected:
	// Called when the game starts
	virtual void BeginPlay() override;


		
};
