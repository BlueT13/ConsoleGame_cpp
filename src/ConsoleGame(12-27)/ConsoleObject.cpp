#include "ConsoleObject.h"

int2 ConsoleObject::GetPos()
{
	return Pos;
}

char ConsoleObject::GetRenderChar()
{
	return RenderChar;
}

void ConsoleObject::SetPos(const int2& _Pos)
{
	Pos = _Pos;
}

void ConsoleObject::SetChar(char _char)
{
	RenderChar = _char;
}