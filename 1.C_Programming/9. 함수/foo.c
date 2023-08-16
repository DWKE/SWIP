// foo.c
#include <stdio.h>

// 전역 변수 / 전역 함수의 앞에 static을 붙이면 내부 연결을 갖습니다.
// => static(통용 범위 지정자)

// 전역 변수는 메모리 영역 중에 DATA 영역을 사용합니다.
// => 초기화된 전역 변수       => .data
//    초기화되지 않은 전역 변수  => .bss

int global = 1000;
static int count = 1000;

// 0000000000000060 D _global => External linkage
// 00000000000000b8 d _count  => Internal linkage

int g1 = 0;
static int g2;
// 0000000000000004 S _g1

// 전역 변수 앞에 static 붙이면
// Internal linkage로 변경됩니다.
// => 다른 파일에서는 접근이 불가능하고
//    같은 파일에서만 접근이 가능합니다.

// 0000000000000000 T _foo => External linkage
// 0000000000000044 t _goo => Internal linkage

static void goo(void)
{
    printf("goo\n");
}

void foo(void)
{
    goo();
    printf("count: %d\n", ++count);
}