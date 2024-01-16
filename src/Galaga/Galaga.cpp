// Galaga.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ConsoleEngine/ConsoleScreen.h>
#include <ConsoleEngine/EngineDebug.h>
#include <list>
#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"

#include "ContentsEnum.h"
#include <ConsoleEngine/EngineCore.h>

int main()
{
    // 몬스터 움직임 만들기

    EngineCore EngineCore;

    EngineCore.Init({ 20, 20 });


    Player* NewPlayer = nullptr;
    {
        // Player* NewObject = new Player();
        NewPlayer = EngineCore.CreateObject<Player>(GalagaUpdateType::Player, GalagaRenderType::Player);
        NewPlayer->SetPos({ EngineCore.Screen.GetScreenX() / 2, EngineCore.Screen.GetScreenY() - 2 });
    }

    {
        const int MonsterCount = EngineCore.Screen.GetScreenX() / 2;
        // const int MonsterCount = 1;
        for (int i = 0; i < MonsterCount; i++)
        {
            Monster* NewObject = EngineCore.CreateObject<Monster>(GalagaUpdateType::Monster, GalagaRenderType::Monster);
            NewObject->SetPlayer(NewPlayer);
            NewObject->SetPos({ i, 0 });
            NewObject->SetRenderChar('&');
        }
    }

    EngineCore.Start();

}