#include "CHUD.h"
#include "Global.h"
#include "Engine/Texture2D.h"
#include "Engine/Canvas.h"

ACHUD::ACHUD()
{
	CHelpers::GetAsset<UTexture2D>(&Texture, "Texture2D'/Game/Textures/T_Crosshair.T_Crosshair'");
	//Texture2D'/Game/Textures/T_Crosshair.T_Crosshair'

}

void ACHUD::DrawHUD()
{
	Super::DrawHUD();

	CheckFalse(bDraw);
	CheckNull(Texture);

	FVector2D center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f); // 비율반으로 줄인다 
	FVector2D size(Texture->GetSurfaceWidth() * 0.5f, Texture->GetSurfaceHeight() * 0.5f);
	FVector2D position = center - size; // 정중앙 세팅 ,센터에서 size만큼 뺀다 ? 

	FCanvasTileItem item(position, Texture->Resource, FLinearColor::White); // 텍스처색이랑 우리가 지정한 색이랑 섞기
	item.BlendMode = SE_BLEND_Translucent;

	Canvas->DrawItem(item);
}
