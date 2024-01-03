#include <iostream>

enum class StringReturn
{
	Equal,
	NotEqual
};

int StringCount(const char* _Ptr)
{
	int count = 0;
	while (_Ptr[count])
	{
		count++;
	}
	return count;
}

StringReturn StringEqual(const char* const _Left, const char* const _Right)
{
	int Lcounts = StringCount(_Left);
	int Rcounts = StringCount(_Right);

	if (Lcounts == Rcounts)
	{
		for (int i = 0; i < Lcounts; i++)
		{
			if (_Left[i] != _Right[i])
			{
				return StringReturn::NotEqual;
			}
		}
	}
	else
	{
		return StringReturn::NotEqual;
	}

	return StringReturn::Equal;
}

void StringAdd(char* _Dest, const char* const _Left, const char* const _Right)
{
	int Lcounts = StringCount(_Left);
	int Rcounts = StringCount(_Right);

	for (int i = 0; i < Lcounts; i++)
	{
		_Dest[i] = _Left[i];
	}

	for (int i = Lcounts; i < Lcounts + Rcounts; i++)
	{
		_Dest[i] = _Right[i - Lcounts];
	}
}

int StringContains(const char* const _Dest, const char* const _Find)
{
	int count = 0;
	int length = StringCount(_Dest);
	int inputStringCounts = StringCount(_Find);

	for (int i = 0; i < length; i++)
	{
		int check = 0;
		int input = i;
		for (int j = 0; j < inputStringCounts; j++)
		{
			if (_Dest[input] == _Find[j])
			{
				check++;
				input++;
			}
		}

		if (check == inputStringCounts)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	{
		// 오른쪽과 왼쪽이 같아?
		StringReturn Equal = StringEqual("AAAA", "AAAA");
	}

	{
		char Arr[100] = {};
		StringAdd(Arr, "ccccc", "ddddd");
		// "cccccddddd"
		int a = 0;
	}

	{
		// int Result = StringContains("ababcccccabab", "ab");

		int Result = StringContains("abababab", "ab");

		int a = 0;
	}
}