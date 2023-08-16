// 10_포인터.c
#include <stdio.h>

// * 변수: 메모리를 할당하고 이름을 부여합니다.
// 1) 모든 할당된 변수는 메모리 주소를 가지고 있습니다.
// 2) 주소 연산자(&)를 이용해서, 메모리 주소를 구할 수 있습니다.
// 3) printf("%p", &n);

// * 포인터(Pointer) 변수
// : 다른 변수의 주소를 보관하는 변수를 "포인터 변수"라고 합니다.

#if 0
int main(void)
{
    int n = 42;
    printf("%p\n", &n); // 0x16af06ea8

    int* pn = &n;
    printf("%p\n", pn); // 0x16af06ea8

    double d = 3.14;
    printf("%p\n", &d); // 0x16b62ae98

    double* pd = &d;
    printf("%p\n", pd); // 0x16b62ae98

    return 0;
}
#endif

int main(void)
{
    int n = 42;

    int* pn = &n;
    // 포인터 변수가 가지고 있는 변수의 주소를 참조해서,
    // 변수의 값을 읽거나 변경할 수 있습니다.

    printf("%d\n", *pn);
    *pn = 100;

    printf("%d\n", n);

    return 0;
}