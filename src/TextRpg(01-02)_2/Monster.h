#pragma once
#include "FightUnit.h"

class Monster : public FightUnit
{
public:
	void FightStart(FightUnit& _Other) override;
	void FightEnd(FightUnit& _Other) override;
};

