// 9_레퍼런스5.cpp

#include <iostream>
using namespace std;

#if 0
int main()
{
    int n = 100;
    int& r = n;
    // r은 n의 메모리에 접근하는 새로운 이름입니다.

    const int& r2 = n;
    // r2은 n의 메모리에 접근하는 새로운 이름입니다.
    // r2를 통해서는 n의 메모리의 값을 변경할 수 없습니다.
}
#endif

#if 0
int main()
{
    int n = 100;
    int x = 1000;

    // int* const p = &n;
    // p = &x; /* 에러!, 포인터 변수가 상수입니다. */

    const int* p = &n;
    // p를 통해서 대상체의 값을 변경할 수 없습니다.
}
#endif

int main()
{
    const int c = 10;

    // const 타입은 const를 가지는 포인터/참조 타입을 통해서만
    // 참조할 수 있습니다.
    const int* p = &c;
    const int& r = c;

    // 일반적인 변수 타입은 일반 포인터 또는 참조 타입을 통해서 참조할수 있고,
    // const 포인터/참조 타입을 통해서도 참조할 수 있습니다.
    int n = 100;
    int* p2 = &n;
    int& r2 = n;

    const int* p3 = &n;
    const int& r3 = n;
}
