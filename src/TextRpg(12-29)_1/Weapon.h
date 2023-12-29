#pragma once
#include "NameUnit.h"
#include <iostream>

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

	void UpLevel();

	void ShowLevel();

private:
	int EquipUp = 0;
	int Att;
};

