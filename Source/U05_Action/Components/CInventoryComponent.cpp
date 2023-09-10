#include "Components/CInventoryComponent.h"
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
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

uint8 UCInventoryComponent::FindIndexByType()
{
	return uint8();
}

void UCInventoryComponent::AddItem()
{
}

void UCInventoryComponent::RemoveItem()
{
}

void UCInventoryComponent::ClearInventory()
{
}

void UCInventoryComponent::DropItem()
{
}

void UCInventoryComponent::UseItem()
{
}

bool UCInventoryComponent::IsSlotEmpty(uint8 index)
{
	


	return false;
}

