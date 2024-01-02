#pragma once
#include "NameUnit.h"

class StatusUnit : public NameUnit
{
public:
	void StatusRender();

	inline void HpReset()
	{
		Hp = MaxHp;
	}

	inline void AddGold(int _Gold)
	{
		Gold += _Gold;
	}

	inline int GetGold()
	{
		return Gold;
	}

	/*void SetInit(int _MaxHp, int  _MinAtt, int _MaxAtt)
	{
		SetMaxHp(_MaxHp);
		SetMinAtt(_MinAtt);
		SetMaxAtt(_MaxAtt);
	}*/

	inline void SetHp(int _Hp)
	{
		if (MaxHp < _Hp)
		{
			Hp = MaxHp;
		}
		Hp = _Hp;
	}

	inline void SetMaxHp(int _MaxHp)
	{
		MaxHp = _MaxHp;
	}

	inline void SetMinAtt(int _MinAtt)
	{
		MinAtt = _MinAtt;
	}

	inline void SetMaxAtt(int _MaxAtt)
	{
		MaxAtt = _MaxAtt;
	}

	void RandomGold(int _Min, int _Max);

protected:
	int Hp = 0;
	int MaxHp = 0;
	int MinAtt = 0;
	int MaxAtt = 0;
	int Speed = 20; // 0~20
	int Gold = 0;
};

