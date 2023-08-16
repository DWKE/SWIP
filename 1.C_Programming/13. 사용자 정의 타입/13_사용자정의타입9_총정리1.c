// 13_사용자정의타입9.c
#include <stdio.h>

// 사용자 정의 타입
// 1) struct(구조체)
// 2) union(공용체)
// 3) enum(열거체)

// 타입을 조합해서, 새로운 타입을 만들 수 있습니다.
struct Complex {
    // 멤버 데이터 변수
    int real;
    int image;
};

#if 0
void PrintComplex(struct Complex complex)
{
    printf("%d + %di\n", complex.real, complex.image);
}
#endif

void PrintComplex(const struct Complex* complex)
{
    // printf("%d + %di\n", (*complex).real, (*complex).image);
    printf("%d + %di\n", complex->real, complex->image);
}

void Add(const struct Complex* lhs, const struct Complex* rhs,
    struct Complex* result)
{
    result->real = lhs->real + rhs->real;
    result->image = lhs->image + rhs->image;
}

int main(void)
{
    struct Complex c1 = { .real = 0, .image = 0 };
    struct Complex c2 = { .real = 10, .image = 3 };

    PrintComplex(&c1);
    PrintComplex(&c2);

    struct Complex result;
    Add(&c1, &c2, &result);

    PrintComplex(&result);

    return 0;
}