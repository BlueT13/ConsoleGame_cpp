#include "ConsoleScreen.h"

// std 및 플랫폼 헤더
#include <iostream>
#include <Windows.h>
#include <assert.h>
#include <conio.h>

// 자체 헤더
#include "ConsoleObject.h"

ConsoleScreen::ConsoleScreen()
{

}
ConsoleScreen::~ConsoleScreen()
{
	ReleaseScreen();
}

void ConsoleScreen::CreateScreen(/*&NewScreen => this, */int _ScreenX, int _ScreenY)
{
	ReleaseScreen();

	if (0 >= _ScreenX)
	{
		MsgBoxAssert("스크린 X크기가 0이기 때문에 콘솔 스크린을 만들수 없습니다");
	}

	if (0 >= _ScreenY)
	{
		MsgBoxAssert("스크린 Y크기가 0이기 때문에 콘솔 스크린을 만들수 없습니다");
	}

	/*this->*/ScreenX = _ScreenX;
	/*this->*/ScreenY = _ScreenY;

	if (0 != ScreenData.size())
	{
		MsgBoxAssert("이미 스크린을 만든 상태에서 다시 만들어졌습니다");
	}

	// std::vector<char>* Ptr = new std::vector<char>[ScreenY];

	ScreenData.resize(ScreenY);
	// ScreenData = new char* [ScreenY];
	if (0 == ScreenData.size())
	{
		MsgBoxAssert("스크린 생성에 실패했습니다. if (nullptr == ScreenData)");
	}

	for (int y = 0; y < ScreenY; y++)
	{
		ScreenData[y].resize(ScreenX + 2);
		// ScreenData[y] = new char[ScreenX + 2] {0,};

		if (0 == ScreenData[y].size())
		{
			MsgBoxAssert("스크린 생성에 실패했습니다. if (nullptr == ScreenData[y])");
		}
	}

	ClearScreen();

	// 함수가 실행되면 스택에 그 함수 이름의 메모리를 그리면
	// 맴버함수는 실행되면 내부에 this가 있다는것을 기억해야 한다.
	// new를 하면 생각할 필요 없다. 일단 영역을 그려야 한다.

}

void ConsoleScreen::ReleaseScreen()
{
	ScreenData.clear();

	// 지울때는 역순으로 지워야 한다.
	//for (int y = 0; y < ScreenY; y++)
	//{
	//	if (nullptr == ScreenData[y])
	//	{
	//		continue;
	//	}

	//	delete[] ScreenData[y];
	//	ScreenData[y] = nullptr;
	//}

	//if (nullptr != ScreenData)
	//{
	//	delete[] ScreenData;
	//	ScreenData = nullptr;
	//}
}

void ConsoleScreen::SetChar(const ConsoleObject& _Object)
{
	SetChar(_Object.GetPos(), _Object.GetRenderChar());
}

void ConsoleScreen::SetChar(const ConsoleObject* _Object)
{
	SetChar(_Object->GetPos(), _Object->GetRenderChar());
}

void ConsoleScreen::SetChar(const int2& _Pos, char _Char)
{
	if (0 > _Pos.Y)
	{
		return;
	}

	if (0 > _Pos.X)
	{
		return;
	}

	if (ScreenX <= _Pos.X)
	{
		return;
	}

	if (ScreenY <= _Pos.Y)
	{
		return;
	}

	ScreenData[_Pos.Y][_Pos.X] = _Char;
}

void ConsoleScreen::ClearScreen()
{
	// char** ScreenData
	// char* ScreenData[0]
	// char ScreenData[0][0]

	// char** ScreenData
	// char* *ScreenData
	// char **ScreenData

	for (int y = 0; y < ScreenY; y++)
	{
		for (int x = 0; x < ScreenX; x++)
		{
			ScreenData[y][x] = '*';
		}
		ScreenData[y][ScreenX] = '\n';
	}
}

void ConsoleScreen::PrintScreen()
{
	system("cls");

	for (int y = 0; y < ScreenY; y++)
	{
		if (0 == ScreenData[y].size())
		{
			MsgBoxAssert("존재하지 않은 라인을 출력하려고 했습니다");
		}

		std::vector<char>& Vector = ScreenData[y];
		char& FirstChar = Vector[0];
		char* PrintPtr = &FirstChar;
		printf_s(PrintPtr);
	}

	ClearScreen();
}