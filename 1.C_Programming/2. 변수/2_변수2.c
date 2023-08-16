// 2_변수2.c
#include <stdio.h>

// 문자 타입, 정수 타입, 실수 타입
// => built-in type(내장 타입)
//    primitive type(원시 타입)

// 1) C 표준에서는 정수 타입의 크기가 표준적으로 정의되어 있지 않습니다.
// => 컴파일러와 시스템에 따라 달라질 수 있습니다.
//  long: 32bit / 64bit

// 2) C 표준에서 타입의 크기가 정의되어 있는 유일한 타입은
//   char 타입 입니다.
// => 1바이트

// 3) char 타입은 3가지가 있습니다.
//  - char(문자 타입)
//  - signed char(부호 있는 1바이트 정수 타입)
//  - unsigned char(부호 없는 1바이트 정수 타입)

// 4) 현업에서 정수 타입을 사용할 때는
//    int, char, long, long long 등의 타입을
//    직접적으로 사용하는 것은 문제가 있습니다.
//  => C99 표준에는 stdint.h 라는 헤더를 제공합니다.

//-----

// * C 언어 타입(64비트 플랫폼 기준)
// - 문자 타입(1바이트)
//  => ASCII
//   'A': 65, 'a': 97, '0': 48

//  char
// - 정수 타입

// * 1바이트 부호 있는 정수 타입 / 부호 없는 정수 타입
// signed char / unsigned char

// * 2바이트 부호 있는 정수 타입 / 부호 없는 정수 타입
//  short / unsigned short

// * 4바이트 부호 있는 정수 타입 / 부호 없는 정수 타입
//  int / unsigned int

// 주의: long => MSVC: 4바이트, GCC/clang: 8바이트

// * 8바이트 부호 있는 정수 타입 / 부호 없는 정수 타입
//  long long / unsigned long long

// - 실수 타입

#if 0
int main(void)
{
    char ch = 'A';
    printf("%d\n", ch); // 65
    printf("%c\n", ch); // 'A'

    return 0;
}
#endif

#if 0
int main(void)
{
    printf("%zu\n", sizeof(long));

    return 0;
}
#endif

#if 0
int main(void)
{
    // char c = 150;
    // signed? unsigned?
    // 표준에서 미지정 사항입니다.
    // => char타입을 1바이트 정수 타입으로 사용하는 경우
    // 반드시 signed / unsigned 명시해야 합니다.
    signed char c1 = 100;
    unsigned c har c2 = 200;

    int n = 100;

    return 0;
}
#endif

#include <stdint.h>

int main(void)
{
    int8_t a;
    uint16_t b;
    int32_t c;
    uint64_t d;

    return 0;
}