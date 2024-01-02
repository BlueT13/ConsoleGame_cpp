#include "Player.h"
#include <iostream>

Player::Player()
{
	// 지금 테스트 코드
	Weapon.SetName("Steel Sword");
	Weapon.SetAtt(10);

	SetCurExp(0);
	SetLevelUpExp(100);
}

void Player::StatusRenderStart()
{
	printf_s("레벨 %d\n", Level);
	printf_s("경험치 %d/%d\n", CurExp, LevelUpExp);
}

void Player::StatusRenderBase()
{
	printf_s("공격력 %d~%d + %d(무기 공격력) + %d(강화 수치)\n", MinAtt, MaxAtt, Weapon.GetAtt(), Weapon.GetEquipUp());
	printf_s("체력 %d/%d\n", Hp, MaxHp);
	printf_s("소지금 %d\n", Gold);
}

int Player::GetRandomAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt() + Weapon.GetEquipUp();
	return CurDamage;
}

void Player::FightEnd(FightUnit& _Other)
{
	int Gold = _Other.GetGold();
	printf_s("플레이어가 %d 골드를 벌었습니다.\n", Gold);
	printf_s("플레이어가 %d 경험치를 얻었습니다.\n", _Other.GetExp());
	AddGold(Gold);

	// 몬스터가 준 경험치죠 _Other.GetExp();
	// AddExp(_Other.GetExp());
	// 나의 경험치 GetExp();
	CurExp += _Other.GetExp();
	if (CurExp >= LevelUpExp)
	{
		Level++;
		CurExp = CurExp % LevelUpExp;
		LevelUp();
	}

	// 나의 능력치를 얼마나 상승시킬지.
	// 다 기획적인 거죠. 상승만 시키세요.

	// LevelUpExp 비교를 해서



	// Monster
}