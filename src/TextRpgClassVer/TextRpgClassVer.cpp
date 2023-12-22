#include <iostream>
#include <conio.h>

class Player
{
public:
	Player()
	{
	}

	void StatusRender()
	{
		// 메모리에 관련된 명확한 설명은 안한 상태지만
		// 자신의 맴버함수에서 자신의 맴버변수는 자유롭게 사용이 가능합니다.
		int Size = printf_s("%s ", Name);
		for (int i = 0; i < 50 - Size; i++)
		{
			printf_s("-");
		}

		printf_s("\n");
		printf_s("공격력 %d\n", Att);
		printf_s("체력 %d\n", Hp);

		for (int i = 0; i < 50; i++)
		{
			printf_s("-");
		}

		printf_s("\n");
	}

	void DamageLogic(int _Att)
	{
		Hp -= _Att;
	}

	int GetAtt()
	{
		return Att;
	}

	void DamageRender()
	{
		printf_s("%s 가 %d의 공격력으로 공격했습니다.\n", Name, Att);
	}

	bool IsDeath()
	{
		return Hp <= 0;
	}

protected:

private:
	char Name[100] = "Fighter";
	int Hp = 100;
	int Att = 10;
};

class Monster
{
public:
	Monster()
	{
	}

	void StatusRender()
	{
		// 메모리에 관련된 명확한 설명은 안한 상태지만
		// 자신의 맴버함수에서 자신의 맴버변수는 자유롭게 사용이 가능합니다.
		int Size = printf_s("%s ", Name);
		for (int i = 0; i < 50 - Size; i++)
		{
			printf_s("-");
		}

		printf_s("\n");
		printf_s("공격력 %d\n", Att);
		printf_s("체력 %d\n", Hp);

		for (int i = 0; i < 50; i++)
		{
			printf_s("-");
		}

		printf_s("\n");
	}

	void DamageLogic(int _Att)
	{
		Hp -= _Att;
	}

	int GetAtt()
	{
		return Att;
	}

	void DamageRender()
	{
		printf_s("%s 가 %d의 공격력으로 공격했습니다.\n", Name, Att);
	}

	bool IsDeath()
	{
		return Hp <= 0;
	}

protected:

private:
	char Name[100] = "Orc";
	int Hp = 50;
	int Att = 5;
};


int main()
{
	// 여기에 몬스터는 없다.
	// 객체지향의 기본은 private함에서 나옵니다.

	// 먼저 존재하게 하기 위해서
	// 상태를 만들었다.

	Player NewPlayer = Player();
	Monster NewMonster = Monster();

	while (true)
	{
		// 나는 몬스터나 플레이어를 눈에보이게 만들고 싶다.
		// 이미 출력된 로직은 우리가 어떻게 할수 없으므로
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		{
			int Input = _getch();
		}

		system("cls");
		NewMonster.DamageLogic(NewPlayer.GetAtt());
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		NewPlayer.DamageRender();

		if (NewMonster.IsDeath())
		{
			printf_s("게임 종료\n");
			break;
		}

		{
			int Input = _getch();
		}

		system("cls");
		NewPlayer.DamageLogic(NewMonster.GetAtt());
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		NewPlayer.DamageRender();
		NewMonster.DamageRender();

		if (NewPlayer.IsDeath() || NewMonster.IsDeath())
		{
			printf_s("게임 종료\n");
			break;
		}

		// 아무키나 눌릴때까지 기다려 줍니다.
		{
			int Input = _getch();
		}

		//NewMonster.IsDeath();
		//NewPlayer.IsDeath();

		// 누군가 죽었다면 게임이 끝나야죠?
		// Player와 몬스터에 bool을 리턴하는 IsDeath()를 만들어서
		// 누구든 Hp가 0이하가 되면 true를 리턴해서
		// 종료가 되게 하세요.
		if (NewPlayer.IsDeath())
		{
			printf_s("게임 종료\n");
			break;
		}

		// 콘솔창에 명령을 요청한다.
		system("cls");
	}
}

