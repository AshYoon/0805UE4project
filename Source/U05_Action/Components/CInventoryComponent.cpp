#include "Components/CInventoryComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Items/ItemBase.h"
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

UItemBase * UCInventoryComponent::FindMathingItem(UItemBase * ItemIn) const
{
	if (ItemIn)
	{
		if (InventoryContents.Contains(ItemIn))
		{
			return ItemIn;
		}
	}
	return nullptr;
}



UItemBase * UCInventoryComponent::FindNextItemById(UItemBase * ItemIn) const
{
	if (ItemIn)
	{
		/*Get ItemBase pointer to result and findbykey with ItemIn*/
		if (const TArray<UItemBase*>::ElementType* Result = InventoryContents.FindByKey(ItemIn))
		{
			/* dereference pointer �������ؼ� �����Ѵ� ���� result�� InventoryContents ItemIn�� ��ġ�ϸ� */
			/*double pointer���� normal pointer�� return */
			return *Result;
		}
	}
	return nullptr;
}

UItemBase * UCInventoryComponent::FindNextPartialStack(UItemBase * ItemIn) const
{
	/*find by predicate - checks with condition  */
	/* �ִ� stack�� �ƴ� �������� ���� �Լ��� ����ؼ� ã�� */
		if (const TArray<UItemBase*>::ElementType* Result = 
			InventoryContents.FindByPredicate([&ItemIn](const UItemBase* InventoryItem)
		{
			return InventoryItem->ID == ItemIn->ID && !InventoryItem->IsFullItemStack();
			
		}
		))
	{
		return *Result;
	}



	return nullptr;


}

int32 UCInventoryComponent::CaculateWeightAddAmoint(UItemBase *ItemIn, int32 RequestedAddAmount)
{

	/* weight capa and total weight is float , �ݿø� Ȥ�� �ݳ��� �ؼ� �Ҽ����� �����ʰ��� */
	const int32 WeightMaxAddAmount = FMath::FloorToInt((GetWeightCapacity() - InventoryTotalWeight) / ItemIn->GetItemSingleWeight());

	if (WeightMaxAddAmount >= RequestedAddAmount)
	{
		return RequestedAddAmount;
	}

	return WeightMaxAddAmount;
}

int32 UCInventoryComponent::CaculateNumberForFullStack(UItemBase * StackableItem, int32 InitialRequestedAddAmount)
{
	const int32 AddAmountToMakeFullStack = StackableItem->NumbericData.MaxStackSize - StackableItem->Quanity;

	return FMath::Min(InitialRequestedAddAmount, AddAmountToMakeFullStack);

}
void UCInventoryComponent::RemoveSingleInstanceOfItem(UItemBase * ItemToRemove)
{
	InventoryContents.RemoveSingle(ItemToRemove);

	/* call delegate , we gonna bind this delegate to ui */
	OnInventoryUpdated.Broadcast();

}

int32 UCInventoryComponent::RemoveAmountOfItem(UItemBase * ItemIn, int32 DesiredAmountToRemove)
{
	// safety check always lesser
	const int32 ActualAmountToRemove = FMath::Min(DesiredAmountToRemove, ItemIn->Quanity);

	ItemIn->SetQuanity(ItemIn->Quanity - ActualAmountToRemove);

	InventoryTotalWeight -= ActualAmountToRemove * ItemIn->GetItemSingleWeight();


	OnInventoryUpdated.Broadcast();

	return ActualAmountToRemove;

}
void UCInventoryComponent::SplitExistingStack(UItemBase * ItemIn, const int32 AmointToSplit)
{
	/*if adding one more thing would overflow your inventory , this will be false */
	if (!(InventoryContents.Num() + 1 > InventorySlotsCapacity))
	{
		RemoveAmountOfItem(ItemIn, AmointToSplit);
		AddNewItem(ItemIn, AmointToSplit);


	}



}

FItemAddResult UCInventoryComponent::HandleNonStackableItem(UItemBase *ItemIn, int32 RequestedAddAmount)
{
	return FItemAddResult();
}


int32 UCInventoryComponent::HandleStackableItems(UItemBase *ItemIn, int32 RequestedAddAmount)
{
	return int32();
}

FItemAddResult UCInventoryComponent::HandleAddItem(UItemBase * InputItem)
{
	

	return FItemAddResult();
}


void UCInventoryComponent::AddNewItem(UItemBase * Item, const int32 AmountToAdd)
{
}







