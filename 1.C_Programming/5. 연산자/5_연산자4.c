// 5_연산자4.c
#include <stdio.h>
#include <stdlib.h>

// 변수가 홀수인지 확인하는 함수를 만들고 싶습니다.
#if 0
int is_odd(int n)
{
    return n % 2 == 1;
}
#endif
// 문제점: 음수가 입력되었을 때, 기대한 결과와 다릅니다.
#if 0
int is_odd(int n)
{
    return abs(n % 2) == 1;
}

int main(void)
{
    printf("%d\n", is_odd(-11));
    printf("%d\n", is_odd(-5));

    return 0;
}
#endif

// 2 => 0000 0010
// 3 => 0000 0011
// 4 => 0000 0100

// -2 => 1111 1110
// -3 => 1111 1101

// 아래 코드의 문제점은 무엇일까요?
int is_even(int n)
{
    return (n & 1) == 0;
}

// 핵심:
//  &,^, |
//  위의 연산을 사용할 때, 우선순위의 문제가 발생할 수 있으므로
//  반드시 괄호를 사용해야 합니다.
#if 0
int main(void)
{
    printf("%d\n", is_even(10));
    printf("%d\n", is_even(20));
    printf("%d\n", is_even(30));
    return 0;
}
#endif

// * C99 표준 이전에는 정수에 대한 나누기/나머지 연산의 결과의 부호가
//   미지정 동작이었습니다.
// * C99 이후에 나누기 / 나머지 연산의 결과의 부호가 나누는 수에 의해서 결정됩니다.
//   N(양수) / or % => 결과(N의 부호를 따릅니다.)

int main(void)
{
    int n = -43;
    printf("%d\n", n / 3); // 몫!
    printf("%d\n", n % 3); // 나머지!

    int x = 0;
    if (x != 0) {
        printf("%d\n", n / x); // 0으로 나누기 => 미정의 동작
        printf("%d\n", n % x); // 0으로 나머지 => 미정의 동작
        // 정수를 나눌 때, 나누는 수가 0이 되지 않도록
        // 반드시 확인하고 처리해야 합니다.
    } else {
        printf("0으로 나눌 수 없습니다!\n");
    }

    return 0;
}