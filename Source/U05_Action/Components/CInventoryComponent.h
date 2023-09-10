#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CInventoryComponent.generated.h"




UENUM(BlueprintType)
enum class E_ItemType : uint8
{
	None,
	Shield,
	Head,
	Top,
	Legs,
	Hand,
	Feet,
	Arrows,
	Tool,
	Material,
	Ring,
	MeleeWeapon,
	RangeWeapon,
	Necklace,

};


UENUM(BlueprintType)
enum class E_StatType : uint8
{
	None,
	Health,
	Stamina,
	Mana,
	Damage,
	Armor,
	CritChance,
	CritMultiplier,
	AttackSpeed,
	Block,
	MeleeAttackStaminaCost,
	MagicDamage,
	CastingSpeed,


};


USTRUCT(BlueprintType)
struct F_Stat
{
	GENERATED_BODY()



	E_StatType Type; // check StatType 
	uint8 ModifierValue; // increase player stat
};



USTRUCT(BlueprintType)
struct F_Item
{
	GENERATED_BODY()


	FName Name;
	FString Description;
	TArray<F_Stat> ItemStat;
	bool IsStackable;
	bool IsDroppable;
	bool IsConsumable;

	UPROPERTY(EditAnywhere, Category = "Item Properties")
		UTexture2D* ItemThumbnail; // Item ThumNail


	




};




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class U05_ACTION_API UCInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	TArray<F_Item> Inventroy;

	TArray<F_Item> GetInventroy() { return Inventroy; }
	uint8 FindIndexByType();

	void AddItem();
	void RemoveItem();
	void ClearInventory();
	void DropItem();
	void UseItem();



private:
	//uint8 index;

	bool IsSlotEmpty(uint8 index);

		
};
