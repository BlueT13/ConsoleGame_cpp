#include "Player.h"
#include "ConsoleScreen.h"

Player::Player() {}
Player::Player(const int2& _StartPos, char _RenderChar) {}

void Player::Update()
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

void Player::SetBulletFire(bool* _IsFire)
{
	if (nullptr == _IsFire)
	{
		return;
	}

	IsFire = _IsFire;
}