#pragma once
#include "ZoneBase.h"
#include "Monster.h"

class FightZone : public ZoneBase
{
public:
	FightZone();

	// 결과가 나올때까지의 전투
	// 전방선언
	// 플레이어 헤더를 여기에 선언하기 싫어서.
	void In(class Player& _Player);

private:
	Monster NewMonster = Monster();

	// 한번의 전투
	// 선언과 구현은 완전히 동일해야 합니다.
	bool FightLogic(FightUnit& _Left, FightUnit& _Right, FightUnit& _Top, FightUnit& _Bot);
};

