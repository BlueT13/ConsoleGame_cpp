#include <iostream>
#include <conio.h>

class int2
{
	// 보통 이런 수학적 클래스는
	// public으로 맴버변수를 두는 편입니다.
public:
	int X = 0;
	int Y = 0;

	// 디폴트 대입연산자.
	void operator=(const int2& _Other)
	{
		X = _Other.X;
		Y = _Other.Y;
	}

	int2 operator+(const int2& _Other)
	{
		return { X + _Other.X, Y + _Other.Y };
	}

	void operator+=(const int2& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
	}
};

const int2 Left = { -1, 0 };
const int2 Right = { 1, 0 };
const int2 Up = { 0, -1 };
const int2 Down = { 0, 1 };

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
	char BaseCh = ' ';
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
};

class Galaga
{
public:
	void GalagaWallDraw(ConsoleScreen& _Screen)
	{
		// [#][#][#][#][#][#]
		// [0][0][0][0][0][0]
		// [0][0][0][0][0][0]
		// [0][0][0][0][0][0]
		// [0][0][0][0][0][0]

		{
			int2 Start0 = { 0, 0 };
			int2 Start1 = { 0, ScreenY - 1 };
			for (int i = 0; i < ScreenX - 1; i++)
			{
				_Screen.SetPixel(Start0, '#');
				_Screen.SetPixel(Start1, '#');
				Start0 += Right;
				Start1 += Right;
			}
		}

		{
			int2 Start0 = { 0, 0 };
			int2 Start1 = { ScreenX - 2, 0 };
			for (int i = 0; i < ScreenY; i++)
			{
				_Screen.SetPixel(Start0, '#');
				_Screen.SetPixel(Start1, '#');
				Start0 += Down;
				Start1 += Down;
			}
		}

	}

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

	void Update()
	{
		// Pos.X += 1;
		// getch의 리턴값을 확인해서

		int Value = _getch();

		switch (Value)
		{
		case 'a':
		case 'A':
		{
			if ((Pos + Left).X != 0)
			{
				Pos += Left;
			}
			break;
		}
		case 'd':
		case 'D':
		{
			if ((Pos + Right).X != (ScreenX - 2))
			{
				Pos += Right;
			}
			break;
		}
		case 'w':
		case 'W':
		{
			if ((Pos + Up).Y != 0)
			{
				Pos += Up;
			}
			break;
		}
		case 's':
		case 'S':
		{
			if ((Pos + Down).Y != (ScreenY - 1))
			{
				Pos += Down;
			}
			break;
		}
		case 'q':
		case 'Q':
		{
			if (nullptr != IsFire)
			{
				*IsFire = true;
			}
			// IsFire = true;
		}
		default:
			break;
		}

		int a = 0;
	}

	void SetBulletFire(bool* _IsFire)
	{
		if (nullptr == _IsFire)
		{
			int a = 0;
			return;
		}

		IsFire = _IsFire;
	}

private:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
	bool* IsFire = nullptr;
};

class Bullet
{
public:
	Bullet(const int2& _StartPos, char _RenderChar)
		: Pos(_StartPos), RenderChar(_RenderChar)
	{
	}

	bool& GetIsFireRef()
	{
		return IsFire;
	}

	inline int2 GetPos()
	{
		return Pos;
	}

	inline char GetRenderChar()
	{
		return RenderChar;
	}

private:
	bool IsFire = false;
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
	Galaga NewGalaga = Galaga();

	Player NewPlayer = Player({ ScreenXHalf, ScreenYHalf }, '@');
	Bullet NewBullet = Bullet({ 0,0 }, '^');

	bool& Ref = NewBullet.GetIsFireRef();
	NewPlayer.SetBulletFire(&Ref);

	while (true)
	{
		NewScreen.ClearScreen();
		NewGalaga.GalagaWallDraw(NewScreen);

		int2 Index = NewPlayer.GetPos();
		char Ch = NewPlayer.GetRenderChar();

		NewScreen.SetPixel(Index, Ch);

		if (true == NewBullet.GetIsFireRef())
		{
			NewScreen.SetPixel(NewBullet.GetPos(), NewBullet.GetRenderChar());
		}

		NewScreen.PrintScreen();
		NewPlayer.Update();
	}
}
