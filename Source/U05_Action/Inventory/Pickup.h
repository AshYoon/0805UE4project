// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Pickup.generated.h"

/**
 * 
 */

//Item Type



UCLASS()
class U05_ACTION_API APickup : public AInteractable
{
	GENERATED_BODY()

public:
		APickup();

		virtual void Interact_Implementation() override; 

		virtual void BeginPlay() override;



		UFUNCTION(BlueprintNativeEvent)
		void Use();
		virtual void Use_Implementation();

		

		enum EItemType : uint8
		{
			Equipment,
			Coin,
			UsableItem,
			ETC,
		};






		UPROPERTY(EditAnywhere, Category = "Pickup Properties")
			UTexture2D* PickupThumbnail; // pickup ������ or ����� 


		UPROPERTY(EditAnywhere, Category = "Pickup Properties")
			FString ItemName;


		


		UPROPERTY(EditAnywhere, Category = "Pickup Properties")
			int32 Value;



		// this is clled when the item is picked up and needs to be cleaned up from the level 
		void OnPickedUp();



		uint8 GetItemType() { return ItemType; };

protected:

	uint8 ItemType; // set ItemType

	
};
