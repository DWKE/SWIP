// 5_연산자.c
#include <stdio.h>

// +, -, *, /, %

// 1) 연산자는 우선순위가 있습니다.

// 2) 동일한 연산자가 다른 의미를 가지는 경우가 있습니다.
//   => 피연산자의 개수가 다릅니다.
//   a + b ; 이항 연산자
//   +a    ; 단항 연산자
//   a - b
//   -a
///  a * b
//   *a  ; 단항 연산자, 포인터 참조 연산

// 3) 연산자는 결합 방향이 존재합니다.
#if 0
int main(void)
{
    int a = (10 + 20 - 30);
    //      ((10 + 20) - 30)

    int b;
    int c;

    // <---------
    a = b = c = 30;
    // a = b = (c = 30)
    // a = (b = 30)
    // a = 30

    return 0;
}
#endif

// 3) ++, -- 증감 연산자
//  => prefix(전위) 증감 연산자
//     postfix(후위) 증감 연산자

#if 0
int main(void)
{
    int n = 10;
    ++n;
    printf("%d\n", n);

    n++;
    printf("%d\n", n);

    return 0;
}
#endif

// ++n: 증가된 값이 결과입니다.
// n++: 증가되기 이전의 값이 결과입니다.
// => 연산의 결과를 이용할 때, 차이가 있습니다.
#if 0
int main(void)
{
    int n = 10;
    int r = 0;

    r = ++n; // n = 11, r = 11
    printf("%d\n", r); // 11

    r = n++; // n = 12, r = 11
    printf("%d\n", r); // 11

    return 0;
}
#endif

#if 0
// ++, -- 전위 후위 증감 연산을 사용할 때,
// 아래와 같은 미정의 동작을 발생시키는 코드가 발생하지 않도록
// 주의해야 합니다.
int main(void)
{
    int n = 10;

    int result = ++n + ++n; /* 미정의 동작 */
    result = ++n + n; /* 미정의 동작 */
    result = n++ + n; /* 미정의 동작 */
    result = n + ++n; /* 미정의 동작 */
    printf("result: %d\n", result); // ???

    return 0;
}
#endif

int main(void)
{
    int a = 0;

    // 복합 대입 연산자
    // +=, -=, *=, /=, %=, ....

    // a의 값을 10 증가하고 싶습니다.
    // a = a + 10;
    a += 10;

    // a의 값을 2배 하고 싶습니다.
    // a = a * 2;
    a *= 2;

    printf("%d\n", a);

    return 0;
}