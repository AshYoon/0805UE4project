#include "CGameMode.h"
#include "Global.h"


ACGameMode::ACGameMode()
{


	// default pawn class는 기본적으로 있는애들이다 
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/Player/BP_CPlayer.BP_CPlayer_C'");


	//Blueprint'/Game/BP_CHUD.BP_CHUD'
	//C 기반 블프니깐 _C를 붙여주는거 잊지말자 
	CHelpers::GetClass<AHUD>(&HUDClass, "Blueprint'/Game/BP_CHUD.BP_CHUD_C'");




}


