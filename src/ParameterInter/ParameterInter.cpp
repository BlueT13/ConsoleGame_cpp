#include <iostream>
using namespace std;

// 선생님이 기본적으로 함수의 인자는 => 지역변수
// 지역변수와 약간 다른점이 있습니다.
void Test(int _Value0, int _Value1, int _Value2, int _Value3)
{
    int* address0 = &_Value0;
    int* address1 = &_Value1;
    int* address2 = &_Value2;
    int* address3 = &_Value3;

    __int64 Address0 = reinterpret_cast<__int64>(address0);
    __int64 Address1 = reinterpret_cast<__int64>(address1);
    __int64 Address2 = reinterpret_cast<__int64>(address2);
    __int64 Address3 = reinterpret_cast<__int64>(address3);

    cout << Address0 << endl;
    cout << Address1 << endl;
    cout << Address2 << endl;
    cout << Address3 << endl;

    // 인자의 주소값은 8바이트 간격으로 떨어져 있음을 확인할 수 있다.
    // 8바이트보다 큰 자료형은 존재하지 X
}


int main()
{
    Test(10, 20, 30, 40);
}