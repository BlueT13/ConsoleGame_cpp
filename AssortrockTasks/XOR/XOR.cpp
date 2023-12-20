﻿#include <iostream>
using namespace std;

int main()
{
    // XOR ( 같으면 0, 다르면 1)
    int a = 0; // 0b00000000000000000000000000000000
    cout << ~a << endl; // -1 or 0b11111111111111111111111111111111

    a = 1;
    int b = a << 31; // b는 음수 최대값 0b10000000000000000000000000000000
    cout << b << endl;

    cout << (-1 ^ b); // 양수 최대값 0b01111111111111111111111111111111

    // 즉, -1에 음수 최대값을 XOR하면 양수 최대값
}