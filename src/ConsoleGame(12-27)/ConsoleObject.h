#pragma once
#include "Math.h"

// 자식들이 공통적으로 가져야할 기능을 만들어 놔야 한다.
class ConsoleObject
{
public:
	int2 GetPos();

	char GetRenderChar();

	void SetPos(const int2& _Pos);

	void SetChar(char _char);

protected:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';

private:

};

