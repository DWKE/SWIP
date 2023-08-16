// 7_제어문3.c
#include <stdio.h>

// 반복문(Iterative Statement)
// 1) while
/*
while (조건식) {
    statement; // 조건식이 참이면 계속 수행됩니다.
}
*/

#if 0
int main(void)
{
    int n;
    scanf("%d", &n);

    int i = 0;
    while (i < n) {
        printf("hello\n");
        ++i;
    }
    // n = 3
    // i = 0, "hello" =>  i = 1
    // i = 1, "hello" =>  i = 2
    // i = 2, "hello" =>  i = 3
    // i = 3  => 조건식이 거짓이므로, 반복문을 탈출합니다.

    return 0;
}
#endif

// 사용자가 -1을 입력할 때까지 입력된 모든 정수의 합을 구하는 프로그램을
// 작성해봅시다.
#if 0
int main(void)
{
    int n = 0;
    int sum = 0; // 값을 누적할 때는 초기화가 반드시 필요합니다.

    while (n != -1) {
        scanf("%d", &n);
        sum = sum + n;
    }

    printf("sum: %d\n", sum);

    return 0;
}
#endif

// break => 반복문을 탈출할 때 사용합니다.
#if 0
int main(void)
{
    int n;
    int sum = 0;

    while (1) { // 무한 루프
        scanf("%d", &n);

        if (n == -1) {
            break; // 반복문을 탈출할 수 있습니다.
        }

        sum += n;
    }

    printf("sum: %d\n", sum);

    return 0;
}
#endif

// 사용자로부터 입력된 수까지의 홀수의 합을 구하는 프로그램을 작성해봅시다.
#if 0
int main(void)
{
    int n;
    int sum = 0;
    scanf("%d", &n);

    int i = 0;
    while (i < n) {
        if ((i + 1) % 2 == 1) {
            sum += (i + 1);
        }

        i++;
    }

    printf("sum: %d\n", sum);

    return 0;
}
#endif

int main(void)
{
    int n;
    int sum = 0;
    scanf("%d", &n);

    // 반복문의 조건을 작성할 때
    // i=0 ~ N-1
    // i=1 ~ N
    // > 위의 조건에 따라서 코드가 달라질 수 있습니다.

    int i = 1;
    while (i <= n) {
        if (i % 2 == 1) {
            sum += i;
        }

        i++;
    }

    printf("sum: %d\n", sum);

    return 0;
}