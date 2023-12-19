#include <iostream>

int StringCount(char* _Ptr)
{
	int Count = 0;
	while (_Ptr[Count])
	{
		++Count;
	}
	return Count;
}

void LeftMoveString(char* _Ptr, int _Start)
{
	if (nullptr == _Ptr)
	{
		return;
	}

	int Count = StringCount(_Ptr);

	// 방어 코드라고 합니다.
	if (0 >= _Start)
	{
		_Start = 1;
	}

	for (int i = _Start - 1; i < Count; i++)
	{
		_Ptr[i] = _Ptr[i + 1];
	}
}

void DeleteChar(char* _Ptr, char _DeleteCh)
{
	int count = StringCount(_Ptr);
	for (int i = 0; i < count; i++)
	{
		if (_Ptr[i] == _DeleteCh)
		{
			LeftMoveString(_Ptr, i + 1);
		}
	}
}

int main()
{
	{
		//               01234
		char Arr[100] = "abcde";
		//LeftMoveString(nullptr, 2);
		LeftMoveString(Arr, 2);
		// acde
	}

	{
		char Arr[100] = "a b c d e";
		DeleteChar(Arr, ' ');
		// Arr = abcde
	}
}