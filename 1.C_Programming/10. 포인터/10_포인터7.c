// 10_포인터7.c
#include <stdio.h>

// 포인터 타입의 크기는 플랫폼과 컴파일러에 따라 다릅니다.
// - 32bit: 포인터 4바이트
// - 64bit: 포인터 8바이트

// 4바이트를 통해서 주소를 표현하게 되면
// 0번지 ~ FFFFFFFF
//  : 바이트 수

//               2^10: 1024바이트(1키로바이트)
//        2^10 * 2^10: 1024키로바이트(1메가바이트)
// 2^10 * 2^10 * 2^10: 1024메가바이트(1기가바이트)
// 2^2 * 2^10 * 2^10 * 2^10: 4기가바이트
#if 0
int main(void)
{
    int* p1;
    int(*p2)[3];

    printf("%zu\n", sizeof(p1));
    printf("%zu\n", sizeof(p2));

    return 0;
}
#endif

// 포인터의 타입은 포인터의 연산을 수행하였을 때
// 바이트의 단위를 결정합니다.

// low                            high
//  [ 0x78 ][ 0x56 ][ 0x34 ][ 0x12 ]   => Little Endian
// => Intel / AMD / ARM
// low                            high
//  [ 0x12 ][ 0x34 ][ 0x56 ][ 0x78 ]   => Big Endian
// => ARM

// : 2바이트 이상의 정수를 메모리에 저장을 할 때,
//   낮은 바이트 부터 높은 수를 저장할지 낮은 수를 저장할지는
//   CPU 마다 다릅니다.
//  => Endian(엔디안)
//     "CPU가 메모리로부터 데이터를 저장하고 불러오는 방식"

//  => 데이터를 교환하는 통신에서는 엔디안을 통일해서 사용합니다.
//    : Big Endian(Network Endian)

//  => C/C++ 프로그램을 작성할 때, 메모리에 저장되는 엔디안을 가정하고
//     코드를 작성하면 안됩니다.
int main(void)
{
    int n = 0x12345678;

    int* pn = &n;
    printf("%X\n", *pn);

    // 메모리를 재해석 하는 목적으로 캐스팅을 사용하였습니다.
    unsigned char* pc = (unsigned char*)&n;
    // printf("%X\n", *pc);
    printf("%X %X %X %X\n", pc[0], pc[1], pc[2], pc[3]);

    // 메모리를 재해석할 때, 매우 주의해야 합니다.
    long long* pl = (long long*)&n;
    printf("%lld\n", *pl); /* 미정의 동작 */

    return 0;
}