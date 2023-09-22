#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MAX 100000

void generateRandBetween(float a, float b, int number, float result[])
{
    int i;
    float x;
    srand(time(NULL));

    for(i = 0; i < number; i++) {
        x = (float)rand()/RAND_MAX;
        result[i] = x*(b - a) + a; 
    }

    return;
}

int main(void)
{   
    int i;
    float result[NUM_MAX];
    float rangeStart, rangeLast;
    int number;
    float sum = 0.0, average = 0.0;


    printf("Enter a start value of range: ");
    scanf("%f", &rangeStart);
    printf("Enter a last value of range: ");
    scanf("%f", &rangeLast);
    printf("Enter the total number of random values to generate: ");
    scanf("%d", &number);

    generateRandBetween(rangeStart, rangeLast, number, result);

    printf("\nRandom values in [%f, %f]\n", rangeStart, rangeLast);
    for(i = 0; i < number; i++) {
        printf("%f ", result[i]); 
    }
    printf("\n");
    
    for(i = 0; i < number; i++) {
        sum += result[i]; 
    }
    average = sum/number;

    printf("The average of random values is %f\n", average);

    return 0;
}