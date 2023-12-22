#include <iostream>
#include <conio.h>

class int2
{
	// 보통 이런 수학적 클래스는
	// public으로 맴버변수를 두는 편입니다.
public:
	int X = 0;
	int Y = 0;
};

// 이런걸 정의하는것을 좋아하지는 안습니다.
//typedef int2 Pos;

// 전역변수는 영역과 관련없이
// 이름이 위에 있다면 그것을 사용할 수 있다.
const int ScreenX = 4;
const int ScreenY = 4;
const int ScreenXHalf = ScreenX / 2;
const int ScreenYHalf = ScreenY / 2;

class ConsoleScreen
{
public:
	// 생성자를 만든다는것은
	// 내가 만든 생성자 형식으로만 생성해라.
	void CreateWall()
	{
		for (int x = 0; x < ScreenX - 1; x++)
		{
			Arr[0][x] = Wall;
		}
		for (int y = 0; y < ScreenY; y++)
		{
			Arr[y][0] = Wall;
		}
		for (int y = 0; y < ScreenY; y++)
		{
			Arr[y][ScreenX - 2] = Wall;
		}
		for (int x = 0; x < ScreenX - 1; x++)
		{
			Arr[ScreenY - 1][x] = Wall;
		}
	}

	bool WallCheck(const int2& _Position)
	{
		return Arr[_Position.Y][_Position.X] == Wall;
	}

	ConsoleScreen(char _BaseChar)
	{
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]

		BaseCh = _BaseChar;
	}

	void PrintScreen()
	{
		for (int y = 0; y < ScreenY; y++)
		{
			char* Ptr = Arr[y];
			printf_s(Ptr);
			printf_s("\n");
		}
	}

	void ClearScreen()
	{
		system("cls");

		for (int y = 0; y < ScreenY; y++)
		{
			for (int x = 0; x < ScreenX - 1; x++)
			{
				Arr[y][x] = BaseCh;
			}
		}
		CreateWall();
	}

	void SetPixel(const int2& _Position, char _Char)
	{
		SetPixel(_Position.X, _Position.Y, _Char);
	}

	void SetPixel(int _X, int _Y, char _Char)
	{
		Arr[_Y][_X] = _Char;
	}

protected:

private:
	char Arr[ScreenY][ScreenX] = { 0, };
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	char BaseCh = ' ';
	char Wall = '#';
};

class Player
{
public:
	Player()
	{
	}

	Player(const int2& _StartPos, char _RenderChar)
		: Pos(_StartPos), RenderChar(_RenderChar)
	{
	}

	// inline은 컴파일러가 함수를 삭제하고
	// 그 위치에 치환시켜 버린다.
	inline int2 GetPos()
	{
		return Pos;
	}

	inline char GetRenderChar()
	{
		return RenderChar;
	}

	void Update(ConsoleScreen& _Screen)
	{
		// Pos.X += 1;
		// getch의 리턴값을 확인해서
		// 상하좌우로 움직이게 하세요.
		int Value = _getch();

		switch (Value)
		{
		case 'a':
		case 'A':
		{
			Pos.X -= 1;
			if (_Screen.WallCheck(Pos))
			{
				Pos.X += 1;
			}
			break;
		}
		case 'd':
		case 'D':
		{
			Pos.X += 1;
			if (_Screen.WallCheck(Pos))
			{
				Pos.X -= 1;
			}
			break;
		}
		case 'w':
		case 'W':
		{
			Pos.Y -= 1;
			if (_Screen.WallCheck(Pos))
			{
				Pos.Y += 1;
			}
			break;
		}
		case 's':
		case 'S':
		{
			Pos.Y += 1;
			if (_Screen.WallCheck(Pos))
			{
				Pos.Y -= 1;
			}
			break;
		}
		default:
			break;
		}


		/* if문
		char ch = static_cast<char>(_getch());

		if (ch == 'a' || ch == 'A')
		{
			Pos.X -= 1;
		}
		else if (ch == 'd' || ch == 'D')
		{
			Pos.X += 1;
		}
		else if (ch == 'w' || ch == 'W')
		{
			Pos.Y -= 1;
		}
		else if (ch == 's' || ch == 'S')
		{
			Pos.Y += 1;
		}*/

	}

private:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
};

// 함수의 실행 메모리는 고정되어 있어야 한다.
// => exe파일에 적혀있다. main함수는 100바이트 사용한다.
// 한번 컴파일이 되고나면 절대로 바뀔수 없다
int main()
{
	// 과제 1
	// 화면 외곽을 벽으로 채워라
	// 플레이어가 벽 바깥으로 못나가게 만들어라.
	// [#][#][#][#][#][0]
	// [#][*][*][*][#][0]
	// [#][*][@][*][#][0]
	// [#][*][*][*][#][0]
	// [#][#][#][#][#][0]

	// 과제 2
	// 플레이어가 키를 누르면
	// [#][#][#][#][#][0]
	// [#][I][*][*][#][0]
	// [#][*][@][*][#][0]
	// [#][*][*][*][#][0]
	// [#][#][#][#][#][0]

	// 변수가 들어갈수 없어요.

	ConsoleScreen NewScreen = ConsoleScreen('*');
	Player NewPlayer = Player({ ScreenXHalf, ScreenYHalf }, '@');
	while (true)
	{
		NewScreen.ClearScreen();

		//int2 Index = NewPlayer.GetPos();
		//char ch = NewPlayer.GetRenderChar();

		NewScreen.SetPixel(NewPlayer.GetPos(), NewPlayer.GetRenderChar());
		NewScreen.PrintScreen();
		NewPlayer.Update(NewScreen);

	}
}
