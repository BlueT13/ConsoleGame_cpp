#pragma once
#include "EngineDebug.h"
#include "ConsoleMath.h"
#include <vector>

// 화면의 크기를 미리 정의하고
// 게임이 실행되면 변경이 불가능했죠.
// 정적 바인딩이라고 합니다.
// 
// 어떤 개념을 배울때 사람들 착각하는게.
// 객체지향 > 절차지향 서로 배척하는 식의 개념이라고 생각한다.
// 
// 정적바인딩보다 좋은 동적바인딩
// 그렇게 생각하면 안되고 그냥 각자를 각자로 받아들어야 합니다.
// 
// 화면크기는 내가 변경할수 있어야하기때문에 동적바인딩
// 목적과 선택
// 
//// 전역변수는 영역과 관련없이
//// 이름이 위에 있다면 그것을 사용할 수 있다.
//const int ScreenX = 20;
//const int ScreenY = 12;
//const int ScreenXHalf = ScreenX / 2;
//const int ScreenYHalf = ScreenY / 2;

// 동적바인딩을 사용하게 되면 메모리 생성 지연을 사용할수 있다.

class ConsoleScreen
{
public:
	ConsoleScreen();
	virtual ~ConsoleScreen();

	void CreateScreen(int _ScreenX, int _ScreenY);
	void ReleaseScreen();
	void PrintScreen();
	void ClearScreen();

	// 전방선언
	void SetChar(const class ConsoleObject& _Object);
	void SetChar(const class ConsoleObject* _Object);
	void SetChar(const int2& _Pos, char _Char);

	inline int GetScreenX() 
	{ 
		return ScreenX; 
	}

	inline int GetScreenY() 
	{ 
		return ScreenY; 
	}

protected:

private:
	// 보통 초기값을 -1을 해놓는 경우가 있다. 
	// 초기화 되지 않았다는것을 표현하기 위해서이다.
	int ScreenX = -1; 
	int ScreenY = -1;

	std::vector<std::vector<char>> ScreenData;
	// char** ScreenData = nullptr; // new int(); => 이걸 언제할지를 프로그래머가 정할수가 있습니다.
	          // 최후최후에 
			  // 내가 원하는 순간 생성을 할수 있다는것.
	          // 사실 2차원 배열이라는것은 인간이 편의성에 의해서 생각한 것뿐이다.
	          // 램이라고 하는 구조가 1차원이기 때문에 존재할수가 없습니다.
	          // 8기가 램 4개를 끼면 2차원
	          // 컴퓨터가 그걸 처리할때 그 하드웨어를 처리할때 분할해서 하지 않기 때문에
	          // 프로그래머에게는 여전히 1차원의 메모리일 뿐이다.

	// char Arr[10 * 10];
};

