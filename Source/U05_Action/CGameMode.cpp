#include "CGameMode.h"
#include "Global.h"


ACGameMode::ACGameMode()
{


	// default pawn class�� �⺻������ �ִ¾ֵ��̴� 
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/Player/BP_CPlayer.BP_CPlayer_C'");


	//Blueprint'/Game/BP_CHUD.BP_CHUD'
	//C ��� �����ϱ� _C�� �ٿ��ִ°� �������� 
	CHelpers::GetClass<AHUD>(&HUDClass, "Blueprint'/Game/BP_CHUD.BP_CHUD_C'");




}


