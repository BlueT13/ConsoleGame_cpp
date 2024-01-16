#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"

// 
// 1. ���� Ư�� �������� �����ߴٸ� ���� �Է¶��� �� �ݴ�������δ� ������ ����.
//    ���� �̵��ϴ� ������ �ݴ�������δ� ���� �ȵȴ�.
// 2. ���� �̵��� �ؼ� CurBody�� ȹ���ߴٸ� �� �������� �� �ٵ�� ���� ����;� �Ѵ�.

void Head::Update()
{
	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();

	// X Y
	// 1 0

	switch (Select)
	{
	case 'A':
	case 'a':
		if (MoveDirection != Right)
		{
			AddPos(Left);
			MoveDirection = Left;
		}
		break;
	case 'S':
	case 's':
		if (MoveDirection != Up)
		{
			AddPos(Down);
			MoveDirection = Down;
		}
		break;
	case 'W':
	case 'w':
		if (MoveDirection != Down)
		{
			AddPos(Up);
			MoveDirection = Up;
		}
		break;
	case 'D':
	case 'd':
		if (MoveDirection != Left)
		{
			AddPos(Right);
			MoveDirection = Right;
		}
		break;
	case '1':
		GetCore()->EngineEnd();
		break;
	default:
		break;
	}




	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("������ �ִ� �ٵ� �������� �ʽ��ϴ�.");
		return;
	}

	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos())
	{
		Back = CurBody;
		BodyManager::ResetBody();
	}

}