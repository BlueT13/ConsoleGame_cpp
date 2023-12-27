#include "Galaga.h"

void Galaga::GalagaWallDraw(ConsoleScreen& _Screen)
{
	// [#][#][#][#][#][#]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]

	{
		int2 Start0 = { 0, 0 };
		int2 Start1 = { 0, ScreenY - 1 };
		for (int i = 0; i < ScreenX - 1; i++)
		{
			_Screen.SetPixel(Start0, '#');
			_Screen.SetPixel(Start1, '#');
			Start0 += Right;
			Start1 += Right;
		}
	}

	{
		int2 Start0 = { 0, 0 };
		int2 Start1 = { ScreenX - 2, 0 };
		for (int i = 0; i < ScreenY; i++)
		{
			_Screen.SetPixel(Start0, '#');
			_Screen.SetPixel(Start1, '#');
			Start0 += Down;
			Start1 += Down;
		}
	}

}