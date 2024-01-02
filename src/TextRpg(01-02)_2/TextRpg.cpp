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

    // FightZone을 3개 만든다.
    // 초급 사냥터
    // 중급 사냥터
    // 고급 사냥터

    // 초급의 몬스터는 Min 5 max 15 Hp 100
    // 중급의 몬스터는 Min 10 max 20 Hp 200
    // 고급의 몬스터는 Min 20 max 40 Hp 300

    // 선택지로 나와야 한다.
    // "1. 마을.\n";
    // "2. 초급 사냥터.\n";
    // "3. 중급 사냥터.\n";
    // "4. 고급 사냥터.\n";


    FightZone NewFightZone[3];
    NewFightZone[0].NewMonster.StatusInit(100, 5, 15);
    NewFightZone[1].NewMonster.StatusInit(200, 10, 20);
    NewFightZone[2].NewMonster.StatusInit(300, 20, 40);

    Town NewTownZone;


    // MainMenu
    while (true)
    {
        NewPlayer.StatusRender();
        printf_s("어디로 가시겠습니다.\n");
        printf_s("1. 마을.\n");
        printf_s("2. 초급 사냥터.\n");
        printf_s("3. 중급 사냥터.\n");
        printf_s("4. 고급 사냥터.\n");
        int Select =_getch();
        system("cls");

        switch (Select)
        {
        case '1':
            NewTownZone.In(NewPlayer);
            break;
        case '2':
        case '3':
        case '4':
        {
            int FightSelect = Select - '2';
            NewFightZone[FightSelect].In(NewPlayer);
            break;
        }
        default:
            break;
        }

        system("cls");

    }

}
