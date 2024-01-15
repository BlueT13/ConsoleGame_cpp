#include "Bullet.h"

Bullet::Bullet()
{
	SetRenderChar('|');
}

void Bullet::Update()
{
	if (0 > GetPos().Y)
	{
		// 모든건 관리되는 구조안에서 지워져야 하기 때문에.
		// 엔진은 이러한 인터페이스를 우리에게 내려줘야 합니다.
		// delete this; <= 내가 지우면 안된다.
		Destroy();
		return;
	}

	AddPos(Up);
}