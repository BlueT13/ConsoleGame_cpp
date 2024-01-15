#include "ConsoleObject.h"
#include "EngineCore.h"


ConsoleObject::ConsoleObject()
{

}

ConsoleObject::ConsoleObject(const int2& _StartPos, char _RenderChar)
	: Pos(_StartPos), RenderChar(_RenderChar)
{

}

ConsoleObject::~ConsoleObject()
{

}

int2 ConsoleObject::GetPos() const
{
	return Pos;
}

char ConsoleObject::GetRenderChar() const
{
	return RenderChar;
}



ConsoleObject* ConsoleObject::Collision(int _UpdateOrder)
{
    std::list<ConsoleObject*>& ObjectList = GetCore()->AllUpdateObject[_UpdateOrder];

    std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
    std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
    for (; StartIter != EndIter; ++StartIter)
    {
        ConsoleObject* Object = *StartIter;

        if (nullptr == Object)
        {
            MsgBoxAssert("오브젝트가 nullptr인 경우가 존재합니다.");
        }

        if (this == Object)
        {
            continue;
        }

        // 이게 충돌
        if (GetPos() == Object->GetPos())
        {
            return Object;
        }
    }

    return nullptr;
}