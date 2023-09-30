// Fill out your copyright notice in the Description page of Project Settings.


#include "World/CPickup.h"
#include "Items/ItemBase.h"


ACPickup::ACPickup()
{
 	PrimaryActorTick.bCanEverTick = false; // we don't need tick 

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");

	PickupMesh->SetSimulatePhysics(true); // set physics , it could be performance issue

	SetRootComponent(PickupMesh);
}


void ACPickup::BeginPlay()
{
	Super::BeginPlay();
	// Set id , Quanity
	InitializePickup(UItemBase::StaticClass(), ItemQuanity);

}





void ACPickup::InitializePickup(const TSubclassOf<UItemBase> BaseClass, const int32 InQuanity)
{
	/*get the itemdata from table and spawn new one */
	if (ItemDataTable && DesiredItemID.IsNone())
	{
		/*rowname = FName , contextstring = my item id */
		const FItemData* ItemData = ItemDataTable->FindRow<FItemData>(DesiredItemID, DesiredItemID.ToString());

		ItemReference = NewObject<UItemBase>(this, BaseClass);

		ItemReference->ID = ItemData->ID;
		ItemReference->ItemType = ItemData->ItemType;
		ItemReference->ItemQuality = ItemData->ItemQuality;
		ItemReference->NumbericData = ItemData->NumbericData;
		ItemReference->ItemTextData = ItemData->ItemTextData;
		ItemReference->AssetData = ItemData->AssetData;

		InQuanity <= 0 ? ItemReference->SetQuanity(1) : ItemReference->SetQuanity(InQuanity);

		PickupMesh->SetStaticMesh(ItemData->AssetData.Mesh);


		UpdataInteractableData();




	}

}

void ACPickup::InitializeDrop(UItemBase * ItemToDrop, const int32 InQuanity)
{
	/*when you drop something and it's already in the inventory , it should be initialized from what's in the inventory
	rather than going searching datatable*/


	ItemReference = ItemToDrop;

	// safe check 
	InQuanity <= 0 ? ItemReference->SetQuanity(1) : ItemReference->SetQuanity(InQuanity);

	ItemReference->NumbericData.Weight = ItemToDrop->GetItemSingleWeight();
	
	PickupMesh->SetStaticMesh(ItemToDrop->AssetData.Mesh);


	UpdataInteractableData();

}


void ACPickup::UpdataInteractableData()
{
	/* any time something change with the pickup , just call this */

	InstanceInteractableData.InteractableType = EInteractableType::Pickup;
	InstanceInteractableData.Action = ItemReference->ItemTextData.InteractionText;
	InstanceInteractableData.Name = ItemReference->ItemTextData.Name;
	InstanceInteractableData.Quantity = ItemReference->Quanity;
	
	InteractableData = InstanceInteractableData;





}






void ACPickup::BeginFocus()
{
	if (PickupMesh)
	{
		PickupMesh->SetRenderCustomDepth(true);
	}
}




void ACPickup::EndFocus()
{
	if (PickupMesh)
	{
		PickupMesh->SetRenderCustomDepth(true);
	}
}


void ACPickup::Interact(ACPlayer * PlayerCharacter)
{
	if (PlayerCharacter)
	{
		TakePickup(PlayerCharacter);
	}
}



void ACPickup::TakePickup(const ACPlayer * Taker)
{


	/*is this item in the process of being deleted ? = ispendingkillpending */
	/* 만약 플레이어가 줍기 키를 연타했을경우를 방지하는 역할 , */
	if (!IsPendingKillPending())
	{
		if (ItemReference)
		{
			//if(UCInventoryComponent* PlayerInventory = Taker->GetInventory())
			// try to add item to player inventory
			// based on result of the add operation
			// adjust or destroy the pickup 

		}
	}
}

