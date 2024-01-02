#include "StatusUnit.h"
#include <iostream>


void StatusUnit::StatusRenderStart()
{

}

void StatusUnit::StatusRenderBase()
{
	printf_s("공격력 %d~%d\n", MinAtt, MaxAtt);
	printf_s("체력 %d/%d\n", Hp, MaxHp);
	printf_s("소지금 %d\n", Gold);
}

void StatusUnit::StatusRenderEnd()
{

}

void StatusUnit::StatusRender()
{
	// 메모리에 관련된 명확한 설명은 안한 상태지만
	// 자신의 맴버함수에서 자신의 맴버변수는 자유롭게 사용이 가능합니다.
	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
	StatusRenderStart();
	StatusRenderBase();
	StatusRenderEnd();

	for (int i = 0; i < 50; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
}

void StatusUnit::RandomGold(int _Min, int _Max)
{
	Gold = (rand() % (_Max - _Min)) + _Min;
}

void StatusUnit::RandomExp(int _Min, int _Max)
{
	Exp = (rand() % (_Max - _Min)) + _Min;
}