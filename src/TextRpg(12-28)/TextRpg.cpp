#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "FightZone.h"

// 0. SetName이 되게 해라.

// 1. 데미지가 Random Damage가 되게 해라.

// 2. 선공 후공이 랜덤이 되게 만들어라.

int main()
{
	Player NewPlayer = Player();

	NewPlayer.SetName("Player");

	FightZone NewZone;

	NewZone.Fight(NewPlayer);

}