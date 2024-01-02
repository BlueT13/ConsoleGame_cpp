#include "NameUnit.h"

void NameUnit::SetName(const char* _Name)
{
	int Count = 0;
	while (_Name[Count])
	{
		++Count;
	}

	for (int i = 0; i < Count + 1; i++)
	{
		Name[i] = _Name[i];
	}

}
