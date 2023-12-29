#pragma once
#include "MyClass.h"

class SubClass : public MyClass
{
public:
	SubClass()
	{
		a = 10;
		b = 10;
	}

	// error: 실행되는 코드는 오직 함수 뿐
	// a = 10; 
};

