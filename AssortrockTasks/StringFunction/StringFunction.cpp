#include <iostream>
using namespace std;

// 공백은 안넣음
// 영어만 취급
// 그리고 끝이 0이 아닌 것은 오류로 취급

int StringCount(const char* _Ptr)
{
	int count = 0;

	// for문으로 시도해봄
	/*for (int i = 0; i < ; i++)
	{
		if (_Ptr[i] != 0)
		{
			count++;
		}
	}*/

	while (_Ptr[count])
	{
		//char Ch = _Ptr[count];
		count++;
	}

	return count;
}

void StringReverse(char* _Ptr)
{
	int length = StringCount(_Ptr);
	for (int i = 0; i < length / 2; i++)
	{
		char a = _Ptr[i];
		_Ptr[i] = _Ptr[length - 1 - i];
		_Ptr[length - 1 - i] = a;
	}
	return;
}

int main()
{
	{
		char Arr[10] = "aaaabbbbe";
		int Result = StringCount(Arr);
		cout << Result << endl;
	}

	{
		char Arr[10] = "ABCDE";
		StringReverse(Arr);
		// 스왑 알고리즘
		//char Ch = Arr[0];
		//Arr[0] = Arr[1];
		//Arr[1] = Ch;

		// EDCBA

		for (int i = 0; i < sizeof(Arr); i++)
		{
			cout << Arr[i] << " ";
		}
	}
}