#include "ConsoleObject.h"


ConsoleObject::ConsoleObject()
{

}

ConsoleObject::ConsoleObject(const int2& _StartPos, char _RenderChar)
	: Pos(_StartPos), RenderChar(_RenderChar)
{

}

ConsoleObject::~ConsoleObject()
{

}

int2 ConsoleObject::GetPos() const
{
	return Pos;
}

char ConsoleObject::GetRenderChar() const
{
	return RenderChar;
}

