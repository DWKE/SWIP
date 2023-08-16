#include <stdio.h>

int cnt;

long int fibonacci(int number);
long int fibonacci_loop(int number);

int main(void) {

    int n;
    scanf("%d", &n);

    printf("Recursive Fibonacci(%d): %ld\n", n, fibonacci(n));
    printf("Count: %d\n", cnt);
    cnt = 0;
    printf("Loop Fibonacci(%d): %ld\n", n, fibonacci_loop(n));
    printf("Count: %d\n", cnt);

    return 0;
}

long int fibonacci(int number)
{
    cnt++;

    if(number-1 <= 1) {
        return number-1;
    } 

    return fibonacci(number-1) + fibonacci(number-2);
}

long int fibonacci_loop(int number)
{
    cnt++;
    long int result = -1;

    if(number-1 <= 1) {
        result = number-1;
    } 
    else {
        int a = 0;
        int b = 1;
        for(int i = 3; i < number; i++) {
            int tmp_a = a;
            a = b;
            b += tmp_a;
        }
        result = a + b;
    }

    return result;
}