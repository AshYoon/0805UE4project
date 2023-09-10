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


	UPROPERTY(EditAnywhere)
	E_StatType Type; // check StatType 


	UPROPERTY(EditAnywhere)
	uint8 ModifierValue; // increase player stat
};



USTRUCT(BlueprintType)
struct F_Item
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FName Name;

	UPROPERTY(EditAnywhere)
	FString Description;

	UPROPERTY(EditAnywhere)
	E_ItemType Type;

	UPROPERTY(EditAnywhere)
	TArray<F_Stat> ItemStat;


	bool IsStackable;
	bool IsDroppable;
	bool IsConsumable;

	UPROPERTY(EditAnywhere, Category = "Item Properties")
		UTexture2D* ItemThumbnail; // Item ThumNail


	UPROPERTY(EditAnywhere, Category = "Item Properties")
		class UStaticMeshComponent* ItemMesh;


	




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

	UPROPERTY(EditAnywhere)
	TArray<F_Item> Inventory;



	TArray<F_Item> GetInventory() { return Inventory; }


    // it could be found more than 1 Item 
	TArray<uint8> FindIndexByType(E_ItemType Type);

	void AddItem(F_Item item);

	void RemoveItem(uint8 index);

	void ClearInventory();

	void DropItem(uint8 index);

	void UseItem(uint8 index);



private:
	//uint8 index;

	bool IsSlotEmpty(uint8 index);

		
};
