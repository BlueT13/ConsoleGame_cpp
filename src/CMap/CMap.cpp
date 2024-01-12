#include <iostream>
#include <map>
#include <ConsoleEngine/EngineDebug.h>

//typedef int KeyType;
//typedef int DataType;
//
// 루트 노드는 부모가 없다는 것을 기억해야 한다.
// delete this;

template<typename KeyType, typename ValueType>
class MyPair
{
public:
	MyPair()
	{

	}

	MyPair(KeyType _first, ValueType _second)
		: Key(_first), Value(_second)
	{

	}

	KeyType Key = KeyType();
	ValueType Value = ValueType();


};

template<typename KeyType, typename ValueType>
class MyMap
{
private:
	class MapNode
	{
	public:
		MyPair<KeyType, ValueType> Pair;
		MapNode* Parent = nullptr;
		MapNode* LeftChild = nullptr;
		MapNode* RightChild = nullptr;

		bool containsNode(const KeyType& _Key)
		{
			if (this->Pair.Key == _Key)
			{
				return true;
			}

			if (this->Pair.Key > _Key)
			{
				if (nullptr != this->LeftChild)
				{
					// 리턴과 동시에 재귀를 하는것을 꼬리 재귀라고 합니다.
					// 컴파일러가 가능하다면 while문 형식으로 바꿔버립니다.
					// inline이랑 비슷하게 생각해라. 
					return this->LeftChild->containsNode(_Key);
				}
			}

			if (this->Pair.Key < _Key)
			{
				if (nullptr != this->RightChild)
				{
					return this->RightChild->containsNode(_Key);
				}
			}


			return false;
		}

		void Release()
		{
			if (nullptr != Parent)
			{
				// 왼쪽 자식이었다는 것
				if (Parent->LeftChild == this)
				{
					Parent->LeftChild = nullptr;
				}

				if (Parent->RightChild == this)
				{
					Parent->RightChild = nullptr;
				}
			}
		}

		MapNode* minnode()
		{
			if (nullptr == this->LeftChild)
			{
				return this;
			}

			return LeftChild->minnode();
		}

		MapNode* maxnode()
		{
			if (nullptr == this->RightChild)
			{
				return this;
			}

			return RightChild->maxnode();
		}

		// 재귀로도 만들수 있는데 while로 해봤다.
		MapNode* OverParent()
		{
			MapNode* PNode = Parent;

			while (PNode)
			{
				if (PNode->Pair.Key > Pair.Key)
				{
					return PNode;
				}

				PNode = PNode->Parent;
			}

			return nullptr;
		}

		MapNode* SmallParent()
		{
			MapNode* PNode = Parent;

			while (PNode)
			{
				if (PNode->Pair.Key < Pair.Key)
				{
					return PNode;
				}

				PNode = PNode->Parent;
			}

			return nullptr;
		}

		void firstOrderPrint()
		{
			// 할일을 맨 앞에서 함.
			std::cout << Pair.Key << std::endl;
			if (nullptr != LeftChild)
			{
				LeftChild->firstOrderPrint();
			}
			if (nullptr != RightChild)
			{
				RightChild->firstOrderPrint();
			}

			return;
		}

		void midOrderPrint()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->midOrderPrint();
			}
			std::cout << Pair.Key << std::endl;
			if (nullptr != RightChild)
			{
				RightChild->midOrderPrint();
			}
			return;
		}

		void lastOrderPrint()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->lastOrderPrint();
			}
			if (nullptr != RightChild)
			{
				RightChild->lastOrderPrint();
			}
			std::cout << Pair.Key << std::endl;
			return;
		}


		void clearNode()
		{
			if (nullptr != this->LeftChild)
			{
				LeftChild->clearNode();
			}
			if (nullptr != this->RightChild)
			{
				RightChild->clearNode();
			}
			delete this;
			return;
		}


		MapNode* NextNode()
		{
			if (nullptr != this->RightChild)
			{
				return this->RightChild->minnode();
			}

			// 부모중에 존재한다.
			return OverParent();
		}

		bool IsLeaf()
		{
			return nullptr == LeftChild && nullptr == RightChild;
		}


		MapNode* PrevNode()
		{
			if (nullptr != this->LeftChild)
			{
				return this->LeftChild->maxnode();
			}

			// 부모중에 존재한다.
			return SmallParent();
		}

		MapNode* findNode(const KeyType& _Key)
		{
			if (this->Pair.Key == _Key)
			{
				return this;
			}

			if (this->Pair.Key > _Key)
			{
				if (nullptr != this->LeftChild)
				{
					// 리턴과 동시에 재귀를 하는것을 꼬리 재귀라고 합니다.
					// 컴파일러가 가능하다면 while문 형식으로 바꿔버립니다.
					// inline이랑 비슷하게 생각해라. 
					return this->LeftChild->findNode(_Key);
				}
			}

			if (this->Pair.Key < _Key)
			{
				if (nullptr != this->RightChild)
				{
					return this->RightChild->findNode(_Key);
				}
			}


			return nullptr;
		}

		void insertNode(MapNode* _Node)
		{
			_Node->Parent = this;
			//        10              5
			if (this->Pair.Key > _Node->Pair.Key)
			{
				if (nullptr == this->LeftChild)
				{
					this->LeftChild = _Node;
					return;
				}

				this->LeftChild->insertNode(_Node);
			}

			if (this->Pair.Key < _Node->Pair.Key)
			{
				if (nullptr == this->RightChild)
				{
					this->RightChild = _Node;
					return;
				}

				this->RightChild->insertNode(_Node);
			}

			return;
		}
	};


public:
	class iterator
	{
		friend MyMap;

	public:
		iterator()
		{
		}

		iterator(MapNode* _CurNode)
			: CurNode(_CurNode)
		{
		}

		MyPair<KeyType, ValueType>* operator->()
		{
			MyPair& MapPair = CurNode->Pair;
			return &MapPair;
		}

		bool operator!=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		void operator++()
		{
			CurNode = CurNode->NextNode();
			return;
		}

	private:
		MapNode* CurNode = nullptr;
	};

	~MyMap()
	{
		clear();
	}

	// map은 자료가 무작위일때 효율을 발휘합니다.
	// 자료가 특정 기준으로 이미 정렬된 상태로 들어간다면 대부분 모두다 맵보다 빠르다.
	void insert(const MyPair<KeyType, ValueType>& _Value)
	{
		MapNode* NewNode = new MapNode();
		NewNode->Pair = _Value;

		// 트리의 기본은 뿌리
		// 최초의 노드는 무조건 뿌리 노드가 될수밖에 없다.
		// 최초에는 root가 nullptr이라면 
		if (nullptr == Root)
		{
			Root = NewNode;
			return;
		}

		Root->insertNode(/*Root, */NewNode);
	}

	bool contains(const KeyType& _Key)
	{
		if (nullptr == Root)
		{
			return false;
		}

		// 안될수도 있다.
		return Root->containsNode(_Key);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	iterator erase(iterator& _Iter)
	{
		iterator Return;

		if (nullptr == _Iter.CurNode)
		{
			MsgBoxAssert("유효하지 않은 원소를 삭제하려고 했습니다.");
			return Return;
		}

		MapNode* NextNode = _Iter.CurNode->NextNode();

		Return.CurNode = NextNode;

		// 일단 처리되면 끝나면 
		if (true == _Iter.CurNode->IsLeaf())
		{
			MapNode* ParentNode = _Iter.CurNode->Parent;
			_Iter.CurNode->Release();
			delete _Iter.CurNode;
			return Return;
		}

		// 교체를 해줘야 한다.
		// 자식이 하나라도 있는 노드이다.
		MapNode* ChangeNode = nullptr;
		MapNode* CurNode = _Iter.CurNode;

		ChangeNode = CurNode->RightChild->minnode();
		if (nullptr == ChangeNode)
		{
			ChangeNode = CurNode->LeftChild->maxnode();
		}

		if (nullptr == ChangeNode)
		{
			MsgBoxAssert("체인지 노드 에러.");
			return Return;
		}
		ChangeNode->Release();

		MapNode* LeftChild = CurNode->LeftChild;
		MapNode* RightChild = CurNode->RightChild;

		if (nullptr != LeftChild)
		{
			LeftChild->Parent = nullptr;
		}

		if (nullptr != RightChild)
		{
			RightChild->Parent = nullptr;
		}

		if (nullptr != LeftChild)
		{
			LeftChild->Parent = ChangeNode;
			if (CurNode->LeftChild != ChangeNode)
			{
				ChangeNode->LeftChild = LeftChild;
			}
		}

		if (nullptr != RightChild)
		{
			RightChild->Parent = ChangeNode;
			if (CurNode->RightChild != ChangeNode)
			{
				ChangeNode->RightChild = RightChild;
			}
		}

		ChangeNode->Parent = CurNode->Parent;
		MapNode* Parent = ChangeNode->Parent;
		if (nullptr != Parent && Parent->LeftChild == CurNode)
		{
			Parent->LeftChild = ChangeNode;
		}

		if (nullptr != Parent && Parent->RightChild == CurNode)
		{
			Parent->RightChild = ChangeNode;
		}

		if (Root == CurNode)
		{
			Root = ChangeNode;
		}

		delete CurNode;

		return Return;

	}


	iterator find(const KeyType& _Key)
	{
		if (nullptr == Root)
		{
			return end();
		}

		// 안될수도 있다.
		return iterator(Root->findNode(_Key));
	}

	iterator begin()
	{
		if (nullptr == Root)
		{
			return end();
		}

		// 안될수도 있다.
		return iterator(Root->minnode());
	}

	void firstOrderPrint()
	{
		Root->firstOrderPrint();
		return;
	}

	void midOrderPrint()
	{
		Root->midOrderPrint();
		return;
	}

	void lastOrderPrint()
	{
		Root->lastOrderPrint();
		return;
	}

	void clear()
	{
		Root->clearNode();
		Root = nullptr;

		return;
	}



	MapNode* Root = nullptr;
};


int main()
{
	LeakCheck;

	{
		std::cout << "std 맵" << std::endl;

		//      Key   Value
		std::map<int, int> NewMap = std::map<int, int>();

		// 이게 Map의 자료를 추가하는 방법 1입니다.
		// 방법이 보통 5가지
		{
			// 맵은 자동으로 내림차순 정렬이 된다.
			// 방법 1 Pair로 하는법
			//NewMap.insert(std::pair<int, int>(5, 12345648915));

			// 방법 2 make_pair
			//NewMap.insert(std::make_pair(2, 12345648915));

			// 방법 3 배열 연산자 식
			//NewMap[3] = 1;

			// std::map<int, int>::value_type == std::pair<int, int>
			// 방법 4 
			//NewMap.insert(std::map<int, int>::value_type(7, 10));
		}

		// 오름차순 작은수 => 큰수로 정렬이 됩니다.
		NewMap.insert(std::pair<int, int>(10, 0));
		NewMap.insert(std::pair<int, int>(10, 2));
		NewMap.insert(std::pair<int, int>(5, 0));
		NewMap.insert(std::pair<int, int>(15, 0));
		NewMap.insert(std::pair<int, int>(12, 0));
		NewMap.insert(std::pair<int, int>(3, 0));
		NewMap.insert(std::pair<int, int>(7, 0));

		// C++20에서만 사용가능
		if (true == NewMap.contains(15))
		{
			int a = 0;
			// 있다.
		}

		std::map<int, int>::iterator FindIter = NewMap.find(15);
		NewMap.erase(FindIter);

		//if (NewMap.end() != NewMap.find(15))
		//{
		//}

		//if (FindIter != NewMap.end())
		//{
		//	// 있다.
		//}

		// 맵을 순회돌리는건 효율적인 일이 아니에요.
		// 개수가 많아지면 많아질수록
		std::map<int, int>::iterator StartIter = NewMap.begin();
		std::map<int, int>::iterator EndIter = NewMap.end();

		for (/*std::list<int>::iterator StartIter = NewList.begin()*/
			; StartIter != EndIter
			; ++StartIter)
		{
			std::cout << "Key : " << StartIter->first << std::endl;
			// std::cout << "Value : " << StartIter->second << std::endl;
		}
	}

	{
		std::cout << "내 맵" << std::endl;
		//      Key   Value
		MyMap NewMap = MyMap<int, int>();

		// 오름차순 작은수 => 큰수로 정렬이 됩니다.
		NewMap.insert(MyPair(10, 0));
		NewMap.insert(MyPair(5, 0));
		NewMap.insert(MyPair(15, 0));
		NewMap.insert(MyPair(12, 99));
		NewMap.insert(MyPair(3, 0));
		NewMap.insert(MyPair(7, 0));

		if (true == NewMap.contains(12))
		{
			int a = 0;
		}


		//MyMap::iterator FindIter =  NewMap.find(12);
		//std::cout << "Key : " << FindIter->Key << std::endl;
		//std::cout << "Value : " << FindIter->Value << std::endl;

		//MyMap::iterator FindIter = NewMap.find(10);
		//NewMap.erase(FindIter);

		std::cout << "first" << std::endl;
		NewMap.firstOrderPrint();
		std::cout << "mid" << std::endl;
		NewMap.midOrderPrint();
		std::cout << "last" << std::endl;
		NewMap.lastOrderPrint();

		//MyMap::iterator StartIter = NewMap.begin();
		//MyMap::iterator EndIter = NewMap.end();



		//for (/*std::list<int>::iterator StartIter = NewList.begin()*/
		//	; StartIter != EndIter
		//	; ++StartIter)
		//{
		//	std::cout << StartIter->Key << std::endl;
		//	//std::cout << StartIter->second << std::endl;
		//}
	}
}
