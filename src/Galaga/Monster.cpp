#include "Monster.h"
#include "ContentsEnum.h"


void Monster::Update()
{
	--Value;
	if (0 >= Value)
	{
		AddPos(Down);
		Dir.X *= -1;
		Value = TurnValue;
	}
	else 
	{
		AddPos(Dir);
	}

	// 여기 내부만 만들면 됩니다.

	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (nullptr != CollisionObject)
	{
		Destroy();
		CollisionObject->Destroy();
	}

}