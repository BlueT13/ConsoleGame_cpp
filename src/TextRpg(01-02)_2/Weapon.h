#pragma once
#include "NameUnit.h"

class Weapon : public NameUnit
{
public:
	inline int GetAtt() const
	{
		return Att;
	}

	inline void SetAtt(int _Att)
	{
		Att = _Att;
	}

	inline int GetEquipUp() const
	{
		return EquipUp;
	}

	inline void EquipLevelUp()
	{
		++EquipUp;
	}

	inline void EquipLevelDown(int _Level)
	{
		EquipUp -= _Level;
	}

	inline void EquipLevelReset()
	{
		EquipUp = 0;
	}

private:
	int EquipUp = 0;
	int Att = 0;
};

