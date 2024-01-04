#include <iostream>

enum class StringReturn
{
	Equal,
	NotEqual
};

// static_cast<int>(strlen())
int StringCount(const char* _Ptr)
{
	int count = 0;
	while (_Ptr[count])
	{
		count++;
	}
	return count;
}

// strcmp()
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

// sprintf_s(Arr, "%s%s", "bbb", "ccc");
void StringAdd(char* _Dest, const char* const _Left, const char* const _Right)
{
	int Dcounts = StringCount(_Dest);
	int Lcounts = StringCount(_Left);
	int Rcounts = StringCount(_Right);


	for (int i = 0; i < Lcounts; i++)
	{
		_Dest[Dcounts] = _Left[i];
		Dcounts++;
	}

	for (int i = Lcounts; i < Lcounts + Rcounts; i++)
	{
		_Dest[Dcounts] = _Right[i - Lcounts];
		Dcounts++;
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
		for (int j = 0; j < inputStringCounts; j++)
		{
		
			if (_Dest[i+j] == _Find[j])
			{
				check++;
			}
			else
			{
				break;
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
		char Arr[100] = { "aa" };
		StringAdd(Arr, "bbb", "ccc");
		int a = 0;
	}

	{
		// int Result = StringContains("ababcccccabab", "ab");

		int Result = StringContains("cccc", "cc");
		int a = 0;
	}
}