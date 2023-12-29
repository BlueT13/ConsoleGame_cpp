#pragma once
#include "FightUnit.h"
#include "Weapon.h"

class Player : public FightUnit
{
public:
	Player();

	// 이런 경우에 public으로 한다.
	// 값으로 들고 있는 경우에는.
	// 보통 이런다.
	// 포인터로 해야 합니다.

	// 내가 만들려는 컨텐츠에 따라서
	// 이걸 값으로 해야할지
	// 포인터로 해야할지.

	// 보통 존재하거나 존재하지 않을 가능성이 있다면 => 포인터
	// 절대로 사라지지 않아야 하면 => 값형
	// 지금은 동적할당을 배우지 않았기 때문에 
	Weapon Weapon;

protected:
	int GetRandomAtt() override;
};

