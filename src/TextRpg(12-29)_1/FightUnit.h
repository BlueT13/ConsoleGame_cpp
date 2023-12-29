#pragma once
#include "StatusUnit.h"

class FightUnit : public StatusUnit
{
public:
	FightUnit();

	// Get
	inline bool IsDeath() const
	{
		return Hp <= 0;
	}

	inline int GetMinAtt() const
	{
		return MinAtt;
	}

	virtual int GetRandomAtt();

	int GetRandomSpeed() const;

	// Fight¿ë ÇÔ¼ö
	void DamageLogic(FightUnit& _Unit);

	void DamageRender();

protected:
	int CurDamage = 0;

private:
};
