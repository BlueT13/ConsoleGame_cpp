#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Monster : public ConsoleObject
{
protected:
	void Update() override;

private:
	int MoveCount = 10;
	int2 Direction = { 1, 0 };
};

