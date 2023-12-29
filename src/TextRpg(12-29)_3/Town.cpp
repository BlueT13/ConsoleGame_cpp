#include "Town.h"
#include <iostream>
#include <conio.h>
#include "Player.h"

void Town::WeaponUp(Player& _Player)
{
	while (true)
	{
		system("cls");

		int EquipUp = _Player.Weapon.GetEquipUp();

		_Player.StatusRender();
		printf_s("---------------------------------------\n");
		printf_s("강화수치 %d\n", EquipUp);
		printf_s("---------------------------------------\n");
		printf_s("1. 강화\n");
		printf_s("2. 나가기\n");

		int Select = _getch();


		switch (Select)
		{
		case '1':
		{
			int EquipUpGold = (EquipUp + 1) * 1000;

			if (EquipUpGold > _Player.GetGold())
			{
				printf_s("돈이 부족하여 강화를 할수가 없습니다.\n");
				int Test = _getch();
				break;
			}

			if (EquipUp >= 30)
			{
				printf_s("최종 강화 상태라 더이상 강화에 도전하실수 없습니다.\n");
				int Test = _getch();
				break;
			}

			// 여기러 왔으면 강화를 할수 있다고 본다.
			_Player.AddGold(-EquipUpGold);

			int Random = rand() % 100;

			if (Random > 10)
			{
				_Player.Weapon.EquipLevelUp();
				printf_s("강화에 성공했습니다.\n");
			}
			else
			{
				int CurEquipUp = _Player.Weapon.GetEquipUp();
				if (10 <= CurEquipUp && 20 >= CurEquipUp)
				{
					_Player.Weapon.EquipLevelDown(5);
				}
				else if (20 <= CurEquipUp)
				{
					_Player.Weapon.EquipLevelReset();
				}

				printf_s("강화에 실패했습니다.\n");
			}
			int Test = _getch();
			break;
		}
		case '2':
			return;
		default:
			break;
		}
	}
	// 여러분들이 건드려야 하는 부분은 여기 뿐입니다.

	// 1. 플레이어의 무기의 강화 상태를 보여준다.
	// 기존 그려졌던 랜더링을 전부다 지우고.
	// 1번선택지는 강화
	//   30강에 도달한 무기는 강화가 안된다고 띄워라.
	// 
	// 2번선택지는 나간다.

	// 2.번
	// 1강부터 10강까지는 실패해도 강화수치가 떨어지지 않습니다.
	// 10강부터 20강까지는 실패하면 강화수치가 5씩 떨어집니다.
	// 20강부터 30강까지는 실패하면 강화수치가 0이 됩니다.
	// 강화확률은 마음대로
}

void Town::Heal(Player& _Player)
{
	_Player.HpReset();

	// 1. 플레이어가 
	// 진짜 치료되게 만들어주세요.
	// 
	// 2. 사냥터의 몬스터가 죽었고 플레이어가
	// 몬스터의 HP가 다시 차게 만드세요.
	// 
	// 3. 몬스터가 죽었을때
	//   플레이어가 골드를 얻게 하세요
	//   골드의 범위는 랜덤하게 정하게 하세요
	//   100~500 <= 할필요는 없다.
	// 
	// 4. 강화 1회당 골드를 소모하게 하세요.
	//   돈이 부족하면 강화할수 없습니다. 라는 메세지가 뜨게하세요.
	//   강화수치마다 강화비용이 증가하게 하세요.
	system("cls");
	_Player.StatusRender();
	printf_s("플레이어는 치료되었습니다.");
	int Select = _getch();
}

void Town::In(Player& _Player)
{
	while (true)
	{
		_Player.StatusRender();
		printf_s("마을에서 무엇을 하시겠습니까.\n");
		printf_s("1. 강화.\n");
		printf_s("2. 치료.\n");
		printf_s("3. 나간다.\n");
		int Select = _getch();

		switch (Select)
		{
		case '1':
			WeaponUp(_Player);
			break;
		case '2':
			Heal(_Player);
			break;
		case '3':
			return;
		default:
			break;
		}

		system("cls");
	}

}
