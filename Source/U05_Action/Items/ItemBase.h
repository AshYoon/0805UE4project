// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Datas/ItemDataStructs.h"
#include "Characters/CPlayer.h"
#include "ItemBase.generated.h"

/**
 * 
 */
//doesn't need to implemnet Just move around our systems
UCLASS()
class U05_ACTION_API UItemBase : public UObject
{
	GENERATED_BODY()

public:
	//=========================================================================
	//                       PROPERTIES & VARIABLES
	//=========================================================================

	// manage with setter 
	UPROPERTY()
	UCInventoryComponent* OwningInventory;




	UPROPERTY(VisibleAnywhere, Category = "Item Data", meta = (UIMin = 1, UIMax = 100))
		int32 Quanity; // == amount 

	UPROPERTY(EditAnywhere, Category = "Item Data")
		FName ID;

	UPROPERTY(EditAnywhere, Category = "Item Data")
		EItemType ItemType;

	UPROPERTY(EditAnywhere, Category = "Item Data")
		EItemQuality ItemQuality;

	UPROPERTY(EditAnywhere, Category = "Item Data")
		FItemStatisics ItemStatisics;

	UPROPERTY(EditAnywhere, Category = "Item Data")
		FItemTextData ItemTextData;

	UPROPERTY(EditAnywhere, Category = "Item Data")
		FItemNumericData NumbericData;

	UPROPERTY(EditAnywhere, Category = "Item Data")
		FItemAssetData AssetData;

	//=========================================================================
	//                       FUNCTIONS 
	//=========================================================================

	UItemBase();

	UItemBase * CreateItemCopy() const ;


	// �����Ϸ��� �Լ� ȣ���� �Լ��� �����ڵ�� ��ü�ϴ� �ζ����Լ��� ����ϴ� Unreal Macro
	// ���� ���, �Լ��� �ζ��εȴٴ°��� ���������� �����ϴ°��� �ƴ�
	// �Ϲ������� Getter Setter���� ���� , �Լ�ȣ�� ������带 ���δ� 
	// ������ ��� ��Ű���� �׻� �ּ��� ������ �ƴ� 
	// way to optimazation , best to use getter setter 

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemStackWeight() const { return Quanity * NumbericData.Weight; };

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemSingleWeight() const { return NumbericData.Weight; };

	UFUNCTION(Category = "Item")
	FORCEINLINE bool IsFullItemStack() const { return Quanity == NumbericData.MaxStackSize; };

	UFUNCTION(Category = "Item")
	void SetQuanity(const int32 NewQuanity);

	UFUNCTION(Category = "Item")
	virtual void Use(ACPlayer * Character);


protected:

	//=========================================================================
	//                       PROPERTIES & VARIABLES
	//=========================================================================

	//TArray has function , key to key find , must be overload == to find key value in TArray 
	bool operator==(const FName& OtherID) const
	{
		return ID == OtherID;
	}

	//=========================================================================
	//                       FUNCTIONS 
	//=========================================================================

	
};
