#pragma once
#include "Part.h"

class Head : public Part
{

protected:
	void Update() override;

private:
	int2 MoveDirection = { 0,0 };
};

