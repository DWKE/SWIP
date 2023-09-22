#include <stdio.h>
#include <time.h>
#include <pthread.h>

#include "rand_between.h"

#define NUM_MAX 100000

int count[4] = {0, 0, 0, 0};

void* simulateMonteCarlo(void* quadrant)
{
    int i;
    float x[NUM_MAX];
    float y[NUM_MAX];  
    int quadrantNumer = *(int*)quadrant;

    switch (quadrantNumer) {
        case 1: 
            generateRandBetween(0.0, 1.0, NUM_MAX, x);
            generateRandBetween(0.0, 1.0, NUM_MAX, y);
            break;
        case 2: 
            generateRandBetween(-1.0, 0.0, NUM_MAX, x);
            generateRandBetween(0.0, 1.0, NUM_MAX, y);
            break;
        case 3: 
            generateRandBetween(-1.0, 0.0, NUM_MAX, x);
            generateRandBetween(-1.0, 0.0, NUM_MAX, y);
            break;
        case 4:
            generateRandBetween(0.0, 1.0, NUM_MAX, x);
            generateRandBetween(-1.0, 0.0, NUM_MAX, y);
            break;
    }

    for(i = 0; i < NUM_MAX; i++)
    {
        if ((x[i]*x[i] + y[i]*y[i]) < 1.0) {
            count[quadrantNumer-1]++;
        }
    }

    pthread_exit(NULL);
}

int main(void)
{   
    int i;
    pthread_t threads[4];
    int quadrantNumer[4] = {1, 2, 3, 4};
    int sum = 0;
    double pi;
    int threadReturn;

    for(i = 0; i < 4; i++)
    {
        pthread_create(&threads[i], NULL, simulateMonteCarlo, &quadrantNumer[i]);
    }

    for (i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    sum = count[0] + count[1] + count[2] + count[3];
    pi = (double) sum / (NUM_MAX);

    printf("Counts: %d %d %d %d\n", count[0], count[1], count[2], count[3]);
    printf("Sum of counts: %d\n", sum);
    printf("The value of PI is %f\n", pi);

    return 0;
}