// 2_변수4.c
#include <stdio.h>
#include <math.h>

// 실수 타입 / 부동 소수점 타입
// => 연산에 오차가 발생합니다.
// - float(4바이트)
// - double(8바이트)
// - long double

// => ==, !=
//   연산을 통해 정확한 결과를 알 수 없습니다.

// => 부동 소수점 타입도 플랫폼과 컴파일러에 따라 크기가
//    다릅니다.

#if 0
int main(void)
{
    printf("%zu\n", sizeof(long double));

    double a = 0.7;
    double b = 0.1 * 7;
    printf("%lf\n", a);
    printf("%lf\n", b);

    if (fabs(a - b) < 0.00000001) {
        printf("같은 값입니다.\n");
    } else {
        printf("같은 값입니다.\n");
    }

#if 0
    if (a == b) {
        printf("같은 값입니다.\n");
    } else {
        printf("다른 값입니다.\n");
    }
#endif

    return 0;
}
#endif

// * 현업에서 float, double에 대해서
//   typedef를 통해 크기를 명시하는 형태로 사용하는 경우가 많습니다.

typedef float float32_t;
typedef double float64_t;

int main(void)
{
    float32_t a;
    float64_t b;

    return 0;
}