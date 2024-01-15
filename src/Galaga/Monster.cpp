#include "Monster.h"
#include "ContentsEnum.h"
#include <ConsoleEngine/EngineCore.h>


void Monster::Update()
{	
	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (nullptr != CollisionObject)
	{
		Destroy();
		CollisionObject->Destroy();
	}


	if (0 >= MoveCount)
	{
		AddPos(Down);
		Direction.X *= -1;
		MoveCount = 10;
	}
	else
	{
		AddPos(Direction);
		MoveCount--;
	}
}