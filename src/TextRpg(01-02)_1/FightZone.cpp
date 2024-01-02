#include "FightZone.h"
#include <conio.h>
#include <iostream>
#include "Player.h"

FightZone::FightZone(int _Level)
{
	NewMonster.SetName("Monster");
}

bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot)
{
	{
		int Input = _getch();
	}

	system("cls");
	_Second.DamageLogic(_First);
	_Top.StatusRender();
	_Bot.StatusRender();
	_First.DamageRender();
	if (true == _Second.IsDeath())
	{
		printf_s("게임 종료\n");
		return true;
	}


	{
		int Input = _getch();
	}

	system("cls");
	_First.DamageLogic(_Second);
	_Top.StatusRender();
	_Bot.StatusRender();
	_First.DamageRender();
	_Second.DamageRender();
	if (true == _First.IsDeath())
	{
		printf_s("게임 종료\n");
		return true;
	}
	{
		int Input = _getch();
	}
	system("cls");

	return false;
}

void FightZone::In(Player& _Player, int _Level)
{
	switch (_Level)
	{
	case 1:
		NewMonster.SetMaxHp(100);
		NewMonster.SetMinAtt(5);
		NewMonster.SetMaxAtt(15);
		break;
	case 2:
		NewMonster.SetMaxHp(200);
		NewMonster.SetMinAtt(10);
		NewMonster.SetMaxAtt(20);
		break;
	case 3:
		NewMonster.SetMaxHp(300);
		NewMonster.SetMinAtt(20);
		NewMonster.SetMaxAtt(40);
		break;
	default:
		break;
	}
	NewMonster.HpReset();
	NewMonster.RandomGold(10000, 100000);

	while (true)
	{
		_Player.StatusRender();
		NewMonster.StatusRender();

		// 선공 후공이 결정 나고
		// 조건에 따라서

		bool IsEnd = false;

		if (_Player.GetRandomSpeed() >= NewMonster.GetRandomSpeed())
		{
			printf_s("플레이어의 선공\n");
			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
		}
		else
		{
			printf_s("몬스터의 선공\n");
			IsEnd = FightLogic(NewMonster, _Player, _Player, NewMonster);
		}

		if (true == IsEnd)
		{
			if (false == _Player.IsDeath())
			{
				int MonsterGold = NewMonster.GetGold();
				printf_s("플레이어가 %d 골드를 벌었습니다.\n", MonsterGold);
				_Player.AddGold(MonsterGold);
				int Test = _getch();
			}

			return;
		}
	}

}