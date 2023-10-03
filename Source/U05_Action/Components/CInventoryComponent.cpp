#include "Components/CInventoryComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Global.h"






UCInventoryComponent::UCInventoryComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

}



void UCInventoryComponent::BeginPlay()
{
	//Super::
		BeginPlay();





}

FItemAddResult UCInventoryComponent::HandleNonStackableItem(UItemBase *, int32 RequestedAddAmount)
{
	return FItemAddResult();
}

int32 UCInventoryComponent::HandleStackableItems(UItemBase *, int32 RequestedAddAmount)
{
	return int32();
}

int32 UCInventoryComponent::CaculateWeightAddAmoint(UItemBase *, int32 RequestedAddAmount)
{
	return int32();
}

int32 UCInventoryComponent::CaculateNumberForFullStack(UItemBase * ExistingItem, int32 RequestedAddAmount)
{
	return int32();
}

void UCInventoryComponent::AddNewItem(UItemBase * item, const int32 AmountToAdd)
{
}

UItemBase * UCInventoryComponent::FindMathingItem(UItemBase * ItemIn) const
{
	return nullptr;
}

UItemBase * UCInventoryComponent::FindNextItemById(UItemBase * ItemIn) const
{
	return nullptr;
}

UItemBase * UCInventoryComponent::FindNextPartialStack(UItemBase * ItemIn) const
{
	return nullptr;
}

FItemAddResult UCInventoryComponent::HandleAddItem(UItemBase * InputItem)
{
	return FItemAddResult();
}

void UCInventoryComponent::RemoveSingleInstanceOfItem(UItemBase * ItemIn)
{
}

int32 UCInventoryComponent::RemoveAmountOfItem(UItemBase * ItemIn, int32 DesiredAmountToRemove)
{
	return int32();
}

void UCInventoryComponent::SplitExistingStack(UItemBase * ItemIn, const int32 AmointToSplit)
{
}
