#pragma once
#include "Part.h"
#include <vector>

class Head : public Part
{

protected:
	void Update() override;

private:
	int2 MoveDirection = { 0,0 };
	std::vector<class Body*> Bodys;
};

