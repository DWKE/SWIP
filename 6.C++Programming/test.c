#include <stdio.h>
#if 0
// test.c
void foo(void) { }
void goo(int x) { }

/*
0000000000000000 T _foo
0000000000000004 T _goo
*/

#include <stdbool.h>

int main(void)
{
    _Bool b;

    bool b2 = true;
    b2 = false;
}
#endif
// int[3];

// 1. 함수의 인자 정보가 동일하고, 함수의 반환 타입이 동일하면
//    같은 함수 타입입니다.
//   => 함수의 시그니처가 동일 하면, 동일한 타입입니다.

// 2. 시그니처가 동일한 함수는 같은 함수 포인터 타입을 사용할 수 있습니다.
//   => 함수 포인터: 함수의 주소를 가지는 포인터 변수

int add(int a, int b) // int(int, int)
{
    return a + b;
}
int sub(int a, int b) // int(int, int)
{
    return a - b;
}

// 함수 포인터 변수: 실행 시간에 어떤 함수를 호출할지 결정할 수 있습니다.
int main(void)
{
    printf("%p\n", &add);
    printf("%p\n", &sub);

    int (*fp)(int, int) = NULL;
    fp = &add;
    fp = &sub;
    int result = (*fp)(10, 20);
    printf("%d\n", result);

    // 아래와 같이 사용하는 것을 허용합니다. => C언어
    fp = add;
    result = fp(10, 20);

    return 0;
}
