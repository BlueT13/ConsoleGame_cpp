#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Player : public ConsoleObject
{
public:
	void KeyInput();

	bool GetIsFire() 
	{
		return IsFire;
	}

	bool GetIsEnd()
	{
		return IsGameEnd;
	}

private:
	bool IsFire = false;
	bool IsGameEnd = false;
};

