#pragma once
class ConsoleUpdater
{
	friend class EngineCore;

public:
	bool IsPendingKill()
	{
		return DeathValue;
	}

	class EngineCore* GetCore()
	{
		return Core;
	}

	void Destroy()
	{
		DeathValue = true;
	}

	virtual void Update()
	{

	}

private:
	bool DeathValue = false;
	class EngineCore* Core = nullptr;

	void SetCore(EngineCore* _Core)
	{
		Core = _Core;
	}
};

