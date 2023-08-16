// 7_제어문5.c
#include <stdio.h>

// 1) while
// 2) do-while
/*
do {

} while (조건식)

문장을 한번 먼저 수행하고, 조건식을 조사합니다.
- 한번은 무조건 수행되어야 할 때, 유용합니다.
*/

// 사용자로부터 10보다 작은 정수를 입력받고 싶습니다.
// 사용자가 잘못 입력한 경우, 다시 입력을 수행해야 합니다.
#if 0
int main(void)
{
    int n;
    scanf("%d", &n);

    while (n >= 10) {
        scanf("%d", &n);
    }

    printf("n: %d\n", n);

    return 0;
}
#endif

#if 0
int main(void)
{
    int n;

    do {
        scanf("%d", &n);
    } while (n >= 10);

    printf("n: %d\n", n);

    return 0;
}
#endif

// 3) for
/*
for (초기화; 조건식; 문장2) {
    문장1;
}
// 초기화 => 조건식 => 참 => 문장1 => 문장2 => 조건식 => 참 => 문장1 => 문장2 => 조건식 => 거짓 => 탈출
*/

#if 0
int main(void)
{
    int i;
    int n;
    scanf("%d", &n);

#if 0
    i = 0;
    while (i < n) {
        printf("%d\n", i + 1);
        i++;
    }
#endif

    // 반복의 구간이 명확할 때, while 보다 좀더 가독성이 좋습니다.
    for (int i = 0; i < n; i++) {
        printf("%d\n", i + 1);
    }

    return 0;
}
#endif

// 1-100 정수 중 홀수의 합을 구하는 프로그램을 작성해봅시다.
#if 0
int main(void)
{
    int sum = 0;

    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 1) {
            sum += i;
        }
    }

    printf("sum: %d\n", sum);

    return 0;
}
#endif

// * continue
//  => 반복문에서 반복문의 이후의 코드를 수행하지 않고,
//     다음 반복문을 수행합니다.
//      for => i++ 동작이 보장되지만,
//      while 에서는 continue를 사용할 때, 반복변수의 값이
//      제대로 변경되는지 확인이 필요합니다.
#if 0
int main(void)
{
    int sum = 0;

#if 0
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) {
            continue;
            // 이후의 코드를 수행하지 않고, i++ 의 코드를 수행합니다.
        }

        sum += i;
    }
#endif
    int i = 1;
    while (i <= 100) {
        if (i % 2 == 0) {
            i++; // 주의 해야 합니다.
            continue;
        }

        sum += i;
        i++;
    }

    printf("sum: %d\n", sum);

    return 0;
}
#endif

int main(void)
{
    // for (; 1;) { } // 무한 반복입니다.
    // for (;;) { } // 무한 반복문입니다.

    while (1) { } // 무한 반복은 while을 사용하는 경우가 많습니다.

    return 0;
}