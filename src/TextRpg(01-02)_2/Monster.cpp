#include "Monster.h"

void Monster::FightStart(FightUnit& _Player)
{
	HpReset(/*this*/);
	RandomGold(1000, 10000);
}

void Monster::FightEnd(/*Monster* const this,*/ FightUnit& _Player)
{
	// 랜덤하게 경험치를 정해야 한다.
	RandomExp(50, 100);
	/*NewMonster.*/
	/*this->*/
}