// ConsoleGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include "ConsoleScreen.h"
#include "Galaga.h"
#include "Bullet.h"
#include "Player.h"

// 함수의 실행 메모리는 고정되어 있어야 한다.
// => exe파일에 적혀있다. main함수는 100바이트 사용한다.
// 한번 컴파일이 되고나면 절대로 바뀔수 없다
int main()
{
	// 과제 1
	// 화면 외곽을 벽으로 채워라
	// 플레이어가 벽 바깥으로 못나가게 만들어라.
	// [#][#][#][#][#][0]
	// [#][*][*][*][#][0]
	// [#][*][@][*][#][0]
	// [#][*][*][*][#][0]
	// [#][#][#][#][#][0]

	// 과제 2
	// 플레이어가 키를 누르면
	// [#][#][#][#][#][0]
	// [#][I][*][*][#][0]
	// [#][*][@][*][#][0]
	// [#][*][*][*][#][0]
	// [#][#][#][#][#][0]


	// 변수가 들어갈수 없어요.
	ConsoleScreen NewScreen = ConsoleScreen('*');
	Galaga NewGalaga = Galaga();

	// Player가 bool& _OtherFire; 총알이 무조건 먼저 만들어져야 한다.
	Bullet NewBullet = Bullet();
	// NewBullet.GetIsFireRef()
	Player NewPlayer = Player();

	NewBullet.SetChar('^');

	NewPlayer.SetPos({ ScreenXHalf,ScreenYHalf });

	bool& Ref = NewBullet.GetIsFireRef();
	NewPlayer.SetBulletFire(&Ref);

	while (true)
	{
		NewScreen.ClearScreen();
		NewGalaga.GalagaWallDraw(NewScreen);

		int2 Index = NewPlayer.GetPos();
		char Ch = NewPlayer.GetRenderChar();

		NewScreen.SetPixel(Index, Ch);

		if (true == NewBullet.GetIsFireRef())
		{
			NewScreen.SetPixel(NewBullet.GetPos(), NewBullet.GetRenderChar());
		}

		NewScreen.PrintScreen();
		NewPlayer.Update();
	}




}
