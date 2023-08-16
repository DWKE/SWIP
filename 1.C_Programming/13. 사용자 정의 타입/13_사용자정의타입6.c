// 13_사용자정의타입6.c
#include <stdio.h>

#if 0
// 1. 구조체 타입(사용자 정의 타입)의 크기는
//    멤버에 의해서 결정됩니다.
// => 구조체 타입의 크기는 멤버의 총합과 일치하지 않을 수 있습니다.
//   "구조체 패딩"
struct AAA {
    int a;
    char b;
    double c;
};

// 0       4       8              16
// |a|a|a|a|b|p|p|p|c|c|c|c|c|c|c|c|-|-|-|-|-|-|-|-|-|-|-|-|

struct BBB {
    char a;
    double b;
    int c;
};
// 0       4       8              16              24
// |a|p|p|p|p|p|p|p|b|b|b|b|b|b|b|b|c|c|c|c|p|p|p|p|-|-|-|-|

// int a
// 0       4       8
// |x|x|p|p|a|a|a|a|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|

// double d;
// 0       4       8
// |x|x|p|p|p|p|p|p|d|d|d|d|d|d|d|d|-|-|-|-|-|-|-|-|-|-|-|-|
//-----
// => CPU가 메모리에 효율적으로 접근하기 위해서
//    변수의 배치를 할 때 정렬(얼라이먼트)이 수행됩니다.
//    정렬로 인해서, 패딩이 발생합니다.

int main(void)
{
    printf("%zu\n", sizeof(struct AAA));
    printf("%zu\n", sizeof(struct BBB));

    int a = 10;
    double b = 3.14;

    printf("%lu\n", (unsigned long)&a);
    printf("%lu\n", (unsigned long)&b);

    return 0;
}
#endif

// 구조체의 패딩을 조절하기 위해서,
// 정렬을 변경할 수 있습니다.
//  => 구조체 패킹
//  => 컴파일러 확장 명령

// : 구조체 메모리를 파일에 저장하거나, 네트워크로 전송하는 경우

// #pragma pack(1)

// MSVC
#if 0
#pragma pack(push, 1)
struct AAA {
    char b;
    double c;
    int a;
};
#pragma pack(pop)
#endif

// GCC / Clang
struct AAA {
    char b;
    double c;
    int a;
} __attribute__((packed)); // 컴파일 지시어

struct BBB {
    int a;
    char b;
    double c;
};

int main(void)
{
    printf("%zu\n", sizeof(struct AAA));
    printf("%zu\n", sizeof(struct BBB));
    return 0;
}