#include "Monster.h"
#include <iostream>

void Monster::StatusRenderEnd()
{
	printf_s("경험치 : %d\n", GetExp());
}

void Monster::FightStart(FightUnit& _Player)
{
	HpReset(/*this*/);
	RandomGold(1000, 10000);
	// 랜덤하게 경험치를 정해야 한다.
	RandomExp(50, 100);
}

void Monster::FightEnd(/*Monster* const this,*/ FightUnit& _Player)
{
	/*NewMonster.*/
	/*this->*/
}