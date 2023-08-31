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

	ItemName = FString("Enter an item name here .. ");




	InteractableHelpText = FString("Press E to pick item up.");

	Value = 0;

}

void APickup::Interact_Implementation()
{


	// all interactive item will use this function 

	ACPlayer* Character = Cast<ACPlayer>(UGameplayStatics::GetPlayerCharacter(this, 0));
	//put code here that places the item int othe characters inventory 

	if (Character->AddItemToInventory(this))
	{
		OnPickedUp();
	}






}

void APickup::BeginPlay()
{
	// (ItemName) : Press E to pick up.
	InteractableHelpText = FString::Printf(TEXT("%s : Press E to pick up. "), *ItemName);


}

void APickup::Use_Implementation()
{

	GLog->Log("Use() from base pickup class : YOU SHOULD NOT BE SEEING THIS");


}

void APickup::OnPickedUp()
{

	InteractableMesh->SetVisibility(false);
	InteractableMesh->SetSimulatePhysics(false);
	InteractableMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}
