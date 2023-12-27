#pragma once
// 상속은 무조건 헤더를 추가해야 합니다.
#include "ConsoleObject.h"

class Bullet : public ConsoleObject
{
public:
	Bullet();
	Bullet(const int2& _StartPos, char _RenderChar);

	bool& GetIsFireRef();

private:
	bool IsFire = false;
};
