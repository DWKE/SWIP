// 5_연산자3.c
#include <stdio.h>

// && => 논리 AND 연산자
// || => 논리 OR 연산자
//  : 단일 회로 성질

// (cond1) && (cond2)
// : cond1과 cond2가 모두 참이어야 결과가 참입니다.

// (cond1) || (cond2)
// : cond1 또는 cond2 둘 중 하나만 참이어도 결과가
//   참 입니다.

#if 0
int main(void)
{
    int a;
    int b;
    int result;
    a = b = result = 0;

    result = a++ && ++b;
    printf("%d %d %d\n", a, b, result);
    // 1 0 0

    a = b = result = 0;
    result = --a || ++b;
    printf("%d %d %d\n", a, b, result);
    // -1 0 1

    return 0;
}
#endif

// &&, || 는 우선순위가 다릅니다.
// => 결합의 우선순위 입니다.
#if 0
int main(void)
{
    int a;
    int b;
    int c;
    int result;
    a = 0;
    b = 0;
    c = 0;

    // result = ++a || (b++ && ++c);
    result = ++a || b++ && ++c;
    printf("%d %d %d %d\n", a, b, c, result);
   
    a = 0;
    b = 0;
    c = 0;
    result = ++a && ++b || c++;
    // result = (++a && ++b) || c++;
    printf("%d %d %d %d\n", a, b, c, result);
    // 1 1 0 1

    return 0;
}
#endif

// 논리 연산자 &&
// 논리 연산자 ||
//  위의 연산자를 함께 사용하는 경우,
//  우선순위가 다른 문제가 있습니다.
// => 명시적으로 괄호를 반드시 사용해야 합니다.
int main(void)
{
    int a;
    int b;
    int c;
    int d;
    int result;
    a = 0;
    b = 0;
    c = 0;
    d = 0;

    // result = (++a || (b++ && c++)) || ++d;
    // 1 0 0 0 1

    result = ++a || b++ && c++ || ++d;
    printf("%d %d %d %d %d\n", a, b, c, d, result);

    return 0;
}