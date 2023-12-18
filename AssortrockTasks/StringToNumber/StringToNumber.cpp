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

int StringToNumber(const char* const _NumberString)
{
	// 글자 개수를 알아내야 합니다.
	// StringCount();
	// * 10을 써야 합니다.
	// / 써야 합니다.
	// for문을 사용해야합니다.
	// 예외처리 안합니다.

	// char Ch = _NumberString[0];
	int count = StringCount(_NumberString);
	int value = 1;

	for (int i = 0; i < count - 1; i++)
	{
		value *= 10;
	}

	int result = 0;

	for (int i = 0; i < count; i++)
	{
		char Ch = _NumberString[i];
		int number = Ch - '0';
		result += number * value;
		value /= 10;
	}

	return result;

	/*int sum = 0;
	for (int i = 0; i < count; i++)
	{
		char Ch = _NumberString[i];
		sum += (Ch - '0') * pow(10, count - 1 - i);
	}

	return sum;*/
}

int main()
{
	int Number = StringToNumber("123456789");
	cout << Number;
}