#include "Bullet.h"

Bullet::Bullet()
{
	SetRenderChar('|');
}

void Bullet::Move()
{
	if (false == IsFire)
	{
		return;
	}

	AddPos(Up);
}