#include "Monster.h"
#include "ContentsEnum.h"


void Monster::Update()
{
	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (nullptr != CollisionObject)
	{
		Destroy();
		CollisionObject->Destroy();
	}

}