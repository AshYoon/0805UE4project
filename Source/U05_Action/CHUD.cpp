#include "CHUD.h"
#include "Global.h"
#include "Widgets/MainMenu.h"
#include "Engine/Texture2D.h"
#include "Engine/Canvas.h"


ACHUD::ACHUD()
{
	CHelpers::GetAsset<UTexture2D>(&Texture, "Texture2D'/Game/Textures/T_Crosshair.T_Crosshair'");
	//Texture2D'/Game/Textures/T_Crosshair.T_Crosshair'

}
void ACHUD::BeginPlay()
{
	Super::BeginPlay();

	//if (MainMenuClass)
	//{
	//	/*UMainMenu::StaticClass()-> if we need this only for C++ use this but half of the widget is the graphical element
	//	and that only exists in the editor, so that is why we use UProperties */
	//	MainMenuWidget = CreateWidget<UMainMenu>(GetWorld(), MainMenuClass);
	//	MainMenuWidget->AddToViewport();
	//	/* similer with hidden */
	//	MainMenuWidget->SetVisibility(ESlateVisibility::Collapsed);

	//}



}
void ACHUD::DisplayMenu()
{


}

void ACHUD::HideMenu()
{


}

void ACHUD::ShowInteractionWidget()
{


}

void ACHUD::HideInteractionWidget()
{


}

void ACHUD::UpdateInteractionWidget(const FInteractableData * InteractionData)
{





}



void ACHUD::DrawHUD()
{
	Super::DrawHUD();

	/*           CROSS HAIR                 */
	CheckFalse(bDraw);
	CheckNull(Texture);

	FVector2D center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f); // ���������� ���δ� 
	FVector2D size(Texture->GetSurfaceWidth() * 0.5f, Texture->GetSurfaceHeight() * 0.5f);
	FVector2D position = center - size; // ���߾� ���� ,���Ϳ��� size��ŭ ���� ? 

	FCanvasTileItem item(position, Texture->Resource, FLinearColor::White); // �ؽ�ó���̶� �츮�� ������ ���̶� ����
	item.BlendMode = SE_BLEND_Translucent;

	Canvas->DrawItem(item);
	/*                                      */






}
