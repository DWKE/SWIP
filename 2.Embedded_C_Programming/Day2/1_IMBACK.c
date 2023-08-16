#include <stdio.h>

void imback(void);
int computeGCD(int x, int y);
long computeLCM(int x, int y);

#if 0
int main(void)
{
    // printf("%d\n", computeGCD(36, 123));
    // printf("%ld\n", computeLCM(36, 123));

    // IAK = MBK + MAC
    int imback_arr[6] = { 1, 2, 3, 4, 5, 6 };

    imback();

    return 0;
}
#endif

void imback()
{
    long lcm_max = 0;
    for(int i = 1; i <= 6; i++) {
        for(int m = 1; m <= 6; m++) {
            if(m == i) continue;
            for(int b = 1; b <= 6; b++) {
                if(b == i || b == m) continue;
                for(int a = 1; a <= 6; a++) {
                    if(a == i || a == m || a == b) continue;
                    for(int c = 1; c <= 6; c++) {
                        if(c == i || c == m || c == b || c == a) continue;
                        for(int k = 1; k <= 6; k++) {
                            if(k == i || k == m || k == b || k == a || k == c) continue;
                            if(i*a*k == m*b*k + m*a*c) {
                                printf("%d%d.%d%d%d%d\n", i, m, b, a, c, k);
                                long lcm = computeLCM(i*10 + m, b*1000 + a*100 + c*10 + k);
                                if(lcm_max < lcm) lcm_max = lcm; 
                            }
                        }
                    }
                }
            }
        }
    }
    printf("MAX LCM(IM,BACK): %ld\n", lcm_max);
}

void imback_dfs()
{
    
}

int computeGCD(int x, int y)
{
    int a, b, c, d;
    if (x >= y) {
        a = x;
        b = y;
    } else {
        a = y;
        b = x;
    }
    c = a / b;
    d = a % b;

    while (d > 0) {
        a = b;
        b = d;
        c = a / b;
        d = a % b;
    }

    return b;
}

long computeLCM(int x, int y)
{
    int a = x;
    int b = y;

    while (a != b) {
        if (a > b) {
            b += y;
        }else {
            a += x;
        }
    }

    return a;
}