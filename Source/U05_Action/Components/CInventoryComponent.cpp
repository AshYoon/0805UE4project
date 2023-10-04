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
			/* dereference pointer 역참조해서 리턴한다 만약 result와 InventoryContents ItemIn과 일치하면 */
			/*double pointer에서 normal pointer로 return */
			return *Result;
		}
	}
	return nullptr;
}

UItemBase * UCInventoryComponent::FindNextPartialStack(UItemBase * ItemIn) const
{
	/*find by predicate - checks with condition  */
	/* 최대 stack이 아닌 아이템을 람다 함수를 사용해서 찾기 */
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

	/* weight capa and total weight is float , 반올림 혹은 반내림 해서 소수점이 들어가지않게함 */
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

FItemAddResult UCInventoryComponent::HandleNonStackableItem(UItemBase * InputItem, int32 RequestedAddAmount)
{

	/*using GetStackWeight to nonstackableItem reason is just generic check , it could be use inputitem get single weight */

	// check if in the input item has valid weight , this should never be true 
	if (FMath::IsNearlyZero(InputItem->GetItemSingleWeight()) || InputItem->GetItemStackWeight() < 0)
	{
		//return added none 
		CLog::Print("Item has notvalid weight ", -1, 10.f, FColor::Red);

		return FItemAddResult::AddedNone(FText::Format(FText::FromString(
			"Could not add {0} to the inventory . Item has invalid weight value . "),InputItem->ItemTextData.Name));
	}

	
	/*will the item weight overflow weight capacity*/
	if (InventoryTotalWeight + InputItem->GetItemSingleWeight() > GetWeightCapacity())
	{
		return FItemAddResult::AddedNone(FText::Format(FText::FromString(
			"Could not add {0} to the inventory . Item would overflow weight limit . "), InputItem->ItemTextData.Name));
	}

	// adding one more item would overflow slot capacity 
	if (InventoryContents.Num() + 1 > InventorySlotsCapacity)
	{
		return FItemAddResult::AddedNone(FText::Format(FText::FromString(
			"Could not add {0} to the inventory . All inventory slots are full . "), InputItem->ItemTextData.Name));
	}

	AddNewItem(InputItem, RequestedAddAmount);
	//return added all request
	return FItemAddResult::AddedAll(RequestedAddAmount,FText::Format(FText::FromString(
		"Successfully added {0} {1} to the inventory . "), RequestedAddAmount, InputItem->ItemTextData.Name));

}


int32 UCInventoryComponent::HandleStackableItems(UItemBase *ItemIn, int32 RequestedAddAmount)
{
	return int32();
}

FItemAddResult UCInventoryComponent::HandleAddItem(UItemBase * InputItem)
{
	if (GetOwner())
	{
		const int32 InitialRequestedAddAmount = InputItem->Quanity;

		/*for nonStackable item */
		if (InputItem->NumbericData.bIsStackable)
		{
			return HandleNonStackableItem(InputItem, InitialRequestedAddAmount);
		}

		// handle stackable 
		const int32 StackableAmountAdded = HandleStackableItems(InputItem, InitialRequestedAddAmount);

		if (StackableAmountAdded == InitialRequestedAddAmount)
		{
			// return add all result 
		}

		if (StackableAmountAdded < InitialRequestedAddAmount && StackableAmountAdded > 0)
		{
			// return added partial result 
		}

		if (StackableAmountAdded <= 0)
		{
			//return added non result 
		}



	}

	return FItemAddResult();
}


void UCInventoryComponent::AddNewItem(UItemBase * Item, const int32 AmountToAdd)
{
	/* all the items are pointer , */

	UItemBase* NewItem;

	//some checks 
	if (Item->bIsCopy || Item->bIsPickup)
	{
		NewItem = Item;
		NewItem->ResetItemFlags();

	}
	else
	{
		NewItem = Item->CreateItemCopy();
	}

	NewItem->OwningInventory = this;
	NewItem->SetQuanity(AmountToAdd);

	InventoryContents.Add(NewItem);
	
	/* it could be stack */
	InventoryTotalWeight += NewItem->GetItemStackWeight();
	OnInventoryUpdated.Broadcast();

}







