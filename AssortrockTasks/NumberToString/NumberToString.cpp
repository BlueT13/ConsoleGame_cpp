#include <iostream>
#include <cmath>
using namespace std;

int StringCount(const char* const _Ptr)
{
	int Count = 0;
	while (_Ptr[Count])
	{
		++Count;
	}
	return Count;
}

void NumberToString(int _Number, char* _Ptr)
{
	int count = 0;
	int num = _Number;
	while (num > 0)
	{
		num /= 10;
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		int divisor = pow(10, count - 1 - i);
		int remainder = _Number / divisor;
		_Number %= divisor;
		_Ptr[i] = remainder + '0';

		cout << _Ptr[i];
	}
}

int main()
{
	char Arr[100] = {};

	NumberToString(123456, Arr);
}