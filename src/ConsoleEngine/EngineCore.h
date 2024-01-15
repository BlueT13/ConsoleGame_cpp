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
	ObjectType* CreateObject(int _UpdateOrder, int _RenderOrder)
	{
		ObjectType* NewObject = new ObjectType();
		NewObject->ConsoleObject::SetCore(this);
		AllUpdateObject[_UpdateOrder].push_back(NewObject);
		AllRenderObject[_RenderOrder].push_back(NewObject);
		return NewObject;
	}

	void EngineEnd()
	{
		EngineUpdate = false;
	}

	// 보통 엄청 무거운 함수가 된다.
	std::list<ConsoleObject*> GetUpdateGroup(int _Order)
	{
		return AllUpdateObject[_Order];
	}

protected:


private:
	std::map<int, std::list<ConsoleObject*>> AllUpdateObject;
	std::map<int, std::list<ConsoleObject*>> AllRenderObject;
	bool EngineUpdate = true;
};

