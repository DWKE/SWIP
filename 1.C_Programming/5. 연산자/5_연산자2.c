// 5_연산자2.c
#include <stdio.h>

// 연산의 결과가 참(1)과 거짓(0)일 수 있습니다.

// 1) ==, !=, >, <, >=, <=
//   "논리 표현식"의 결과는 참(1) 또는 거짓(0) 입니다.

// 2) 0은 거짓으로 평가됩니다.
//    0이 아닌값은 참으로 평가됩니다.
#if 0
int main(void)
{
    int a = 10;
    int b = 20;

    printf("%d\n", a == b); // 거짓, 0
    printf("%d\n", a != b); // 참,  1

    int codition = -1;
    if (codition) {
        printf("조건이 참입니다.\n");
    } else {
        printf("조건이 거짓입니다.\n");
    }

    return 0;
}
#endif

// C 언어에 참/거짓을 표현하는 타입이 도입되었습니다.
//  : _Bool

//  C99 표준에 도입되었습니다.
#include <stdbool.h>
// typedef _Bool bool;

int main(void)
{
    _Bool a = 10;
    printf("%d\n", a); // 1

    bool b = true;
    bool c = false;

    return 0;
}