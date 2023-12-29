// TextRpg.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "FightZone.h"
#include <conio.h>
#include "Town.h"

// 0. SetName이 되게 해라.

// 1. 데미지가 Random Damage가 되게 해라.

// 2. 선공 후공이 랜덤이 되게 만들어라.

int main()
{
    int Value = 0;
    __int64 Seed = reinterpret_cast<__int64>(&Value);
    srand(static_cast<unsigned int>(Seed));

    Player NewPlayer = Player();
    NewPlayer.SetName("Player");

    FightZone NewFightZone;
    Town NewTownZone;


    // MainMenu
    while (true)
    {
        NewPlayer.StatusRender();
        printf_s("어디로 가시겠습니다.\n");
        printf_s("1. 마을.\n");
        printf_s("2. 사냥터.\n");
        printf_s("3. 종료.\n");
        int Select =_getch();

        system("cls");

        switch (Select)
        {
        case '1':
            NewTownZone.In(NewPlayer);
            break;
        case '2':
            NewFightZone.In(NewPlayer);
            break;
        case '3':
            return 0;
        default:
            break;
        }

        system("cls");

    }

}
