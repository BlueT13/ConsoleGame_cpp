#include "Weapon.h"
#include <iostream>
#include <conio.h>
#include <time.h>

void Weapon::UpLevel()
{
	int LevelUpPercent = rand() % 101;

	if (LevelUpPercent <= 10)
	{
		printf_s("강화에 실패하였습니다.\n");
		if (EquipUp < 10)
		{
			printf_s("무기의 강화수치가 그대로 유지됩니다.\n");
		}
		else if (EquipUp >= 10 && EquipUp < 20)
		{
			EquipUp -= 5;
			printf_s("무기의 강화수치가 5만큼 떨어졌습니다.");
		}
		else if (EquipUp >= 20)
		{
			EquipUp = 0;
			printf_s("무기의 강화수치가 0으로 떨어졌습니다.");
		}
		int Select = _getch();
	}
	else
	{
		printf_s("강화에 성공하였습니다!");
		EquipUp++;
		int Select = _getch();
	}
}

void Weapon::ShowLevel()
{
	while (EquipUp < 30)
	{
		printf_s("무기는 최대 30강까지 강화가 가능합니다.\n");
		printf_s("1강부터 10강까지는 실패해도 강화수치가 떨어지지 않습니다.\n");
		printf_s("10강부터 20강까지는 실패하면 강화수치가 5씩 떨어집니다.\n");
		printf_s("20강부터 30강까지는 실패하면 강화수치가 0이 됩니다.\n");
		printf_s("---------------------------------------------------------------\n");
		printf_s("현재 무기는 %d강입니다.\n", EquipUp);
		printf_s("강화하시겠습니까?\n");
		printf_s("1. 네.\n");
		printf_s("2. 아니오.\n");
		int Select = _getch();

		switch (Select)
		{
		case '1':
			UpLevel();
			break;
		case '2':
			return;
		default:
			break;
		}

		if (EquipUp >= 30)
		{
			system("cls");
			printf_s("무기가 이미 최대 강화 수치(30강)입니다.\n");
			int Select = _getch();
			return;
		}

		system("cls");
	}
}