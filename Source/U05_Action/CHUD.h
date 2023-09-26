#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CHUD.generated.h"


struct FInteractableData;
class UMainMenu;
class UInteractionWidget;


UCLASS()
class U05_ACTION_API ACHUD : public AHUD
{
	GENERATED_BODY()


public:

	//=========================================================================
	//                       PROPERTIES & VARIABLES
	//=========================================================================


	/*it's a way to enforce types in the editor */
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UMainMenu> MainMenuClass;





	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UInteractionWidget> InteractionWidgetClass;

	// when this true , aiming will be false 
	bool bIsMenuVisible;
	//=========================================================================
	//                       FUNCTIONS 
	//=========================================================================

	/* cross hair */
	FORCEINLINE void SetDrawMode() { bDraw = true; }
	FORCEINLINE void SetUndrawMode() { bDraw = false; }
	virtual void DrawHUD() override;

	/*defualt contructer*/
	ACHUD();

	void DisplayMenu();
	void HideMenu();
	void ShowInteractionWidget();
	void HideInteractionWidget();
	/* just get the reference */
	void UpdateInteractionWidget(const FInteractableData* InteractionData);



protected:
	//=========================================================================
	//                       PROPERTIES & VARIABLES
	//=========================================================================
	UPROPERTY()
		UMainMenu* MainMenuWidget;

	UPROPERTY()
		UInteractionWidget* InteractionWidget;
	//=========================================================================
	//                       FUNCTIONS 
	//=========================================================================

	virtual void BeginPlay() override;


private:

	/* for cross hair */
	UPROPERTY(EditDefaultsOnly)
		class UTexture2D* Texture;



	bool bDraw;





};
