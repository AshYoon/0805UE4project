#include "Components/CInventoryComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Global.h"






UCInventoryComponent::UCInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCInventoryComponent::BeginPlay()
{
	//Super::
		BeginPlay();

	// ...
		//ClearInventory();



}


// Called every frame
void UCInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//Super::
		TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<uint8> UCInventoryComponent::FindIndexByType(E_ItemType Type)
{
	// if we want to found some Items with same ItemType 
	// Use this function to found some Same ItemType Items or Item 
	TArray<uint8> Index;
	for (int i = 0; i < Inventory.Num(); i++)
	{
		
		if (Inventory[i].Type == Type)
		{
			Index.Push(i);
		}
	}

	return Index;
}

void UCInventoryComponent::AddItem(F_Item item)
{
	Inventory.Push(item);
}

void UCInventoryComponent::RemoveItem(uint8 index)
{
	Inventory.RemoveAt(index);

}

void UCInventoryComponent::ClearInventory()
{

	for (int i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i].Type != E_ItemType::None)
		{
			Inventory.RemoveAt(i);
		}
	}

}

void UCInventoryComponent::DropItem(uint8 index)
{


}

void UCInventoryComponent::UseItem(uint8 index)
{


}



//EmptySlotCheck
bool UCInventoryComponent::IsSlotEmpty(uint8 index)
{
	if (Inventory.IsValidIndex(index))
	{
		if (Inventory[index].Type != E_ItemType::None)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}


	
}

