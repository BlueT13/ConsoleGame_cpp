#include "Monster.h"

void Monster::FightStart(FightUnit& _Player)
{
	HpReset(/*this*/);
	RandomGold(1000, 10000);
}

void Monster::FightEnd(/*Monster* const this,*/ FightUnit& _Player)
{
	// �����ϰ� ����ġ�� ���ؾ� �Ѵ�.
	RandomExp(50, 100);
	/*NewMonster.*/
	/*this->*/
}