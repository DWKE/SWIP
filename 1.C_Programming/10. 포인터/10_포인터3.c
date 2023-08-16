// 10_포인터3.c
#include <stdio.h>

#if 0
int main(void)
{
    int a = 10;
    int b = 20;

    int temp = a;
    a = b;
    b = temp;
    printf("%d %d\n", a, b);

    return 0;
}
#endif

#if 0
void Swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;

    Swap(a, b);
    printf("%d %d\n", a, b);

    return 0;
}
#endif

// 직접 Call by reference를 이용해서 위의 코드를 수정해보세요.
void Swap(int* pa, int* pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;

    Swap(&a, &b);
    printf("%d %d\n", a, b);

    return 0;
}