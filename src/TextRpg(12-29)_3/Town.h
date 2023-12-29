#pragma once
#include "ZoneBase.h"

class Town : public ZoneBase
{
public:
	void In(Player& _Player) override;

	void WeaponUp(Player& _Player);
	void Heal(Player& _Player);
};

