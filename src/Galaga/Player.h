#pragma once
#include <ConsoleEngine/ConsoleObject.h>
#include <list>
#include <map>

class Player : public ConsoleObject
{
public:

	bool GetIsFire() 
	{
		return IsFire;
	}

	bool GetIsEnd()
	{
		return IsGameEnd;
	}

protected:
	void Update() override;

private:
	//std::list<Monster*>
	// Monster*
	bool IsFire = false;
	bool IsGameEnd = false;
};

