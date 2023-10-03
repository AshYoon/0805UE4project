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


void UCInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//Super::
		TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
