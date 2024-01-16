#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;
};

