#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Bullet : public ConsoleObject
{
public:
	Bullet();

protected:
	void Update() override;
};

