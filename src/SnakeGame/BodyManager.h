#pragma once
#include <ConsoleEngine/ConsoleUpdater.h>

class BodyManager : public ConsoleUpdater
{
public:
	static class Body* GetCurBody()
	{
		return CurBody;
	}

	static void ResetBody()
	{
		CurBody = nullptr;
	}
	

	void Update() override;

private:
	static class Body* CurBody;
};

