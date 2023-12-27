#include "Bullet.h"
#include "ConsoleScreen.h"

Bullet::Bullet() {}

Bullet::Bullet(const int2& _StartPos, char _RenderChar) {}

bool& Bullet::GetIsFireRef()
{
	return IsFire;
}