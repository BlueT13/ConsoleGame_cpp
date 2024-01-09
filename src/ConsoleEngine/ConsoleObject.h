#pragma once
#include "ConsoleMath.h"

class ConsoleObject
{
public:
	ConsoleObject();
	ConsoleObject(const int2& _StartPos, char _RenderChar);
	~ConsoleObject();

	int2 GetPos() const;
	char GetRenderChar() const;

	inline void SetRenderChar(char _Ch)
	{
		RenderChar = _Ch;
	}

	inline void SetPos(const int2& _Pos)
	{
		Pos = _Pos;
	}

	inline void AddPos(const int2& _Dir)
	{
		Pos += _Dir;
	}

protected:

private:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
};


