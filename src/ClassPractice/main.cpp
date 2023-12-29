#include <iostream>
#include "MyClass.h"

int main()
{
	MyClass NewClass = MyClass();

	NewClass.a = 10;
	// NewClass.b = 20; protected 접근 불가
	// NewClass.c = 30; private 접근 불가

	NewClass.CoutA();
	// NewClass.CoutB(); protected 접근 불가
	// NewClass.CoutC(); private 접근 불가
}