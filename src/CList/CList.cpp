#include <iostream>
#include <list>
#include <ConsoleEngine/EngineDebug.h>

typedef int DataType;

// 노드형태입니다.
class MyList
{
	// Node가 데이터를 1개 받기 때문입니다.
	// 더미노드라는 방식을 사용할 겁니다.
private:
	class ListNode
	{
	public:
		DataType Data = DataType();
		ListNode* Next = nullptr;
		ListNode* Prev = nullptr;
	};


public:
	class iterator
	{
		// class MyList전방 선언과 동시에 friend를 건건데
		// mylist가 뭔지 알기 때문에.
		friend MyList;

	public:
		iterator()
		{
		}

		iterator(ListNode* _CurNode)
			: CurNode(_CurNode)
		{
		}
		
		bool operator!=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		DataType& operator*()
		{
			return CurNode->Data;
		}

		// 연산자 겹지정 중에 
		void operator++()
		{
			CurNode = CurNode->Next;
		}


	private:
		ListNode* CurNode = nullptr;
	};


	MyList()
	{
		Start->Next = End;
		End->Prev = Start;
	}

	~MyList()
	{
		ListNode* CurNode = Start;
		while (CurNode)
		{
			ListNode* Next = CurNode->Next;
			if (nullptr != CurNode)
			{
				delete CurNode;
				CurNode = Next;
			}
		}
	}

	iterator begin()
	{
		return iterator(Start->Next);
	}

	iterator end()
	{
		return iterator(End);
	}

	// End의 Prev에 새로운 데이터를 넣겠다.
	void push_back(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Data = _Data;

		NewNode->Next = End;
		NewNode->Prev = End->Prev;

		ListNode* PrevNode = NewNode->Prev;
		ListNode* NextNode = NewNode->Next;

		PrevNode->Next = NewNode;
		NextNode->Prev = NewNode;
	}

	// Start의 Next에 새로운 데이터를 넣겠다.
	void push_front(const DataType& _Data)
	{
		// 역함수
		ListNode* NewNode = new ListNode();
		NewNode->Data = _Data;

		NewNode->Prev = Start;
		NewNode->Next = Start->Next;

		ListNode* PrevNode = NewNode->Prev;
		ListNode* NextNode = NewNode->Next;

		PrevNode->Next = NewNode;
		NextNode->Prev = NewNode;

	}

	iterator erase(iterator& _Iter)
	{
		if (_Iter.CurNode == Start)
		{
			MsgBoxAssert("Start를 삭제하려고 했습니다.");
		}

		if (_Iter.CurNode == End)
		{
			MsgBoxAssert("End를 삭제하려고 했습니다.");
		}

		iterator ReturnIter;

		if (nullptr != _Iter.CurNode)
		{
			// 다음 노드를 리턴
			ReturnIter = iterator(_Iter.CurNode->Next);

			ListNode* PrevNode = _Iter.CurNode->Prev;
			ListNode* NextNode = _Iter.CurNode->Next;

			PrevNode->Next = NextNode;
			NextNode->Prev = PrevNode;

			// 삭제하기 전에
			// 삭제한다는것은 데이터를 전부다 지우겠다는 건데.
			// 지운걸 사용할수 없다.
			if (nullptr == _Iter.CurNode)
			{
				delete _Iter.CurNode;
				_Iter.CurNode = nullptr;
			}
		}

		return ReturnIter;
	}


protected:

private:

	ListNode* Start = new ListNode();
	ListNode* End = new ListNode();
};

int main()
{
	LeakCheck;

	{
		std::cout << "std 리스트" << std::endl;
		std::list<int> NewList = std::list<int>();
		for (int i = 0; i < 5; i++)
		{
			NewList.push_back(i);
			// NewList.push_front();
		}

		std::list<int>::iterator StartIter = NewList.begin();
		std::list<int>::iterator EndIter = NewList.end();

		// 지워진 노드의 다음 노드를 리턴합니다.
		StartIter = NewList.erase(StartIter);

		for (/*std::list<int>::iterator StartIter = NewList.begin()*/
			; StartIter != EndIter
			; ++StartIter)
		{
			std::cout << *StartIter << std::endl;
			// std::cout << StartIter.operator*() << std::endl;
		}
	}

	{
		std::cout << "내 리스트" << std::endl;
		MyList NewList = MyList();
		for (int i = 0; i < 10; i++)
		{
			NewList.push_front(i);
			// NewList.push_front();
		}

		MyList::iterator StartIter = NewList.begin();
		MyList::iterator EndIter = NewList.end();

		StartIter = NewList.erase(StartIter);

		for (/*std::list<int>::iterator StartIter = NewList.begin()*/
			; StartIter != EndIter
			; ++StartIter
			)
		{
			std::cout << *StartIter << std::endl;
			// std::cout << StartIter.operator*() << std::endl;
		}
	}
}