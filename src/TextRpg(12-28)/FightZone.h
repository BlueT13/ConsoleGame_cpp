#pragma once
#include "Monster.h"

class FightZone
{
public:
	// 결과가 나올때까지의 전투
	void Fight(FightUnit& _Player);

private:
	Monster NewMonster = Monster();

	// 한번의 전투
	// 선언과 구현은 완전히 동일해야 합니다.
	bool FightLogic(FightUnit& _Left, FightUnit& _Right, FightUnit& _Top, FightUnit& _Bot);
};