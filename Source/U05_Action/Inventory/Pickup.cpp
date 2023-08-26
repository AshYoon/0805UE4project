// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Pickup.h"
#include "Characters/CPlayer.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"

//#include "Inventory.h"


APickup::APickup()
{
	//set up the mesh for the pickup , and set the item name , help text and item value 
	InteractableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickMesh"));


	InteractableMesh->SetSimulatePhysics(true);

}

void APickup::Interact_Implementation()
{


	// all interactive item will use this function 

	ACPlayer* Character = Cast<ACPlayer>(UGameplayStatics::GetPlayerCharacter(this, 0));
	//put code here that places the item int othe characters inventory 

	OnPickedUp();






}

void APickup::OnPickedUp()
{

	InteractableMesh->SetVisibility(false);
	InteractableMesh->SetSimulatePhysics(false);


}
