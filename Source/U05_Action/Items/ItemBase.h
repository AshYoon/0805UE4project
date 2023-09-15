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


	// 컴파일러가 함수 호출을 함수의 실제코드로 대체하는 인라인함수를 사용하는 Unreal Macro
	// 성능 향상, 함수가 인라인된다는것을 절대적으로 보장하는것은 아님
	// 일반적으로 Getter Setter에서 사용됨 , 함수호출 오버헤드를 줄인다 
	// 성능을 향상 시키지만 항상 최선의 선택은 아님 
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
