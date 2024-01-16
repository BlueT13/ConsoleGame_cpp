#pragma once

#include <map>
#include <list>

#include "ConsoleScreen.h"
#include "ConsoleObject.h"


class EngineCore
{
	friend class ConsoleObject;

public:
	// 보통 애가 클래스
	// 어차피 자신의 맴버변수는 자기 스스로가 알아서 지키겠지.
	ConsoleScreen Screen = ConsoleScreen();

	void Init(int2 _ScreenSize);
	void Start();

	template<typename ObjectType, typename EnumType>
	ObjectType* CreateObject(EnumType _Order)
	{
		return CreateObject<ObjectType>(_Order, _Order);
	}

	template<typename ObjectType, typename UpdateEnumType, typename RenderEnumType>
	ObjectType* CreateObject(UpdateEnumType _UpdateOrder, RenderEnumType _RenderOrder)
	{
		return CreateObject<ObjectType>(static_cast<int>(_UpdateOrder), static_cast<int>(_RenderOrder));
	}

	template<typename ObjectType>
	ObjectType* CreateObject(int _UpdateOrder = 0, int _RenderOrder = 0)
	{
		ObjectType* NewObject = new ObjectType();
		NewObject->ConsoleUpdater::SetCore(this);
		AllUpdateObject[_UpdateOrder].push_back(NewObject);
		AllRenderObject[_RenderOrder].push_back(NewObject);
		return NewObject;
	}

	template<typename ObjectType>
	ObjectType* CreateManager(int _UpdateOrder)
	{
		if (true == AllManager.contains(_UpdateOrder))
		{
			MsgBoxAssert("이미 존재하는 순서의 매니저에 또 만들려고 했습니다.");
			return nullptr;
		}

		ObjectType* NewObject = new ObjectType();
		NewObject->ConsoleUpdater::SetCore(this);
		AllManager[_UpdateOrder] = NewObject;
		return NewObject;
	}

	void EngineEnd()
	{
		EngineUpdate = false;
	}

	template<typename EnumType>
	std::list<ConsoleObject*> GetUpdateGroup(EnumType _Order)
	{
		return GetUpdateGroup(static_cast<int>(_Order));
	}

	// const int& GetUpdateGroup(int _Order)

	// 보통 엄청 무거운 함수가 된다.
	std::list<ConsoleObject*> GetUpdateGroup(int _Order = 0)
	{
		return AllUpdateObject[_Order];
	}

protected:


private:
	// 관리감독하는 기능들을 여기에 모아 놓으라는 것.
	std::map<int, ConsoleUpdater*> AllManager;

	// 실제 움직이는 애들
	std::map<int, std::list<ConsoleObject*>> AllUpdateObject;
	std::map<int, std::list<ConsoleObject*>> AllRenderObject;
	bool EngineUpdate = true;
};

