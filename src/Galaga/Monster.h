#pragma once
#include <ConsoleEngine/ConsoleObject.h>

// class Player;
class Monster : public ConsoleObject
{
public:
	void SetPlayer(class Player* _MainPlayer)
	{
		MainPlayer = _MainPlayer;
	}

protected:
	void Update() override;

private:
	Player* MainPlayer = nullptr;
	const int TurnValue = 11;
	int Value = TurnValue;
	int2 Dir = Right;
};

