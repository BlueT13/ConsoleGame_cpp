#include <iostream>
#include <vector>

// 자료구조의 메모리의 2가지 형태중 하나로서
// 어떠한 데이터가 자기자신의 데이터의 참조형을 n개 가지면 
// 그걸 노드구조라고 한다.

typedef int DataType;

class Node
{
public:
    DataType Value;
    Node* Next = nullptr;
    Node* Prev = nullptr;
};

class Zone
{
public:
    std::vector<Zone*> LinkZone;
};

int main()
{
    int Value0;
    int Value1;

    Node Node0;
    Node Node1;
    Node Node2;
    Node Node3;
    Node Node4;
    Node Node5;
    Node Node6;

    Node0.Value = 0;
    Node1.Value = 1;
    Node2.Value = 2;
    Node3.Value = 3;
    Node4.Value = 4;
    Node5.Value = 5;
    Node6.Value = 6;

    Node0.Next = &Node1;
    Node1.Next = &Node2;
    Node2.Next = &Node3;
    Node3.Next = &Node4;
    Node4.Next = &Node5;
    Node5.Next = &Node6;


    Node1.Prev = &Node0;
    Node2.Prev = &Node1;
    Node3.Prev = &Node2;
    Node4.Prev = &Node3;
    Node5.Prev = &Node4;
    Node6.Prev = &Node5;

    // CurNode 만 가지고
    // 나머지 모든 값을 출력하세요.
    Node* CurNode = &Node0;
    while (nullptr != CurNode)
    {
        std::cout << CurNode->Value << std::endl;
        CurNode = CurNode->Next;
    }

    CurNode = &Node6;
    while (nullptr != CurNode)
    {
        std::cout << CurNode->Value << std::endl;
        CurNode = CurNode->Prev;
    }

    // 배열 형태는 중간에 있는 자료값을 변경하기 위해 다음과 같은 과정을 거쳐야하지만
    int Arr[10] = { 0, 1, 2, 3, 4, 5, 6 };

    for (int i = 2; i < 6; i++)
    {
        Arr[i] = Arr[i + 1];
    }

    // 노드 형태는 링크 설정만 변경하면 직관적이고 간단하게 중간에 있는 자료값을 변경할 수 있다.
    Node1.Next = &Node3;
}
