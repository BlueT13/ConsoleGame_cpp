#include <iostream>

int StringCount(const char* const _Ptr)
{
	int count = 0;
	while (_Ptr[count])
	{
		count++;
	}

	return count;
}

int CharConvert(char* _String, char _PrevCh, char _NextCh)
{
	int count = 0;
	int convertCount = 0;
	while (_String[count])
	{
		if (_String[count] == _PrevCh)
		{
			_String[count] = _NextCh;
			convertCount++;
		}
		count++;
	}

	return convertCount;
}

int main()
{
	char Arr[10] = "aaabbbccc"; // aaabbbccc0

	int Result = CharConvert(Arr, 'b', 'd');
	// "aaadddccc"

	std::cout << Result;
}

//#include <iostream>
//
//int StringCount(const char* const _Ptr)
//{
//	int count = 0;
//	while (_Ptr[count])
//	{
//		count++;
//	}
//
//	return count;
//}
//
//int CharConvert(char* _String, char _PrevCh, char _NextCh)
//{
//	int count = StringCount(_String);
//	int convertCount = 0;
//	for (int i = 0; i < count; i++)
//	{
//		if (_String[i] == _PrevCh)
//		{
//			_String[i] = _NextCh;
//			convertCount++;
//		}
//	}
//
//	return convertCount;
//}
//
//int main()
//{
//	char Arr[10] = "aaabbbccc";
//
//	int Result = CharConvert(Arr, 'b', 'd');
//	// "aaadddccc"
//
//	std::cout << Result;
//}