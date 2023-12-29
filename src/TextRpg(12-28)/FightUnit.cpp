#include "FightUnit.h"
#include <iostream>

FightUnit::FightUnit()
{
}

void FightUnit::DamageLogic(const FightUnit& _Unit)
{
	int UnitRandDamage = _Unit.MinAtt + rand() % (_Unit.MaxAtt - _Unit.MinAtt + 1);

	Hp -= UnitRandDamage;
}

void FightUnit::DamageRender()
{
	printf_s("%s 가 %d~%d의 공격력으로 공격했습니다.\n", Name, MinAtt, MaxAtt);
}