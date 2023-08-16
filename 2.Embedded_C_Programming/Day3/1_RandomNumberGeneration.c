#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandBetween(float a, float b, int number, float result[]);

#if 0
int main(void)
{
    float start, finish;
    int totalNum;
    

    printf("Enter a start value of range: ");
    scanf("%f", &start);
    printf("Enter a finish value of range: ");
    scanf("%f", &finish);
    printf("Enter the total number of random values to generate: ");
    scanf("%d", &totalNum);

    float* result = malloc(sizeof(float) * totalNum);

    generateRandBetween(start, finish, totalNum, result);

    for (int i=0; i<totalNum; i++) {
        printf("%f ", result[i]);
    }

    return 0;
}

#endif

// 대부분의 operation이 randomness를 preserve하지 못함
// Exclusive OR 이 randomness preserve함
void generateRandBetween(float a, float b, int number, float result[])
{
    srand((unsigned)time(NULL));

    for (int i=0; i<number; i++) {
        result[i] = a + rand() * ((b - a) / RAND_MAX);
    }
}