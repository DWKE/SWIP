#include <stdio.h>
#include <time.h>
#include <pthread.h>

#include "2_rand_between.h"

#define NUM_MAX 100000

int count[4] = {0, 0, 0, 0};
enum { X = 0, Y = 1 };

void* simulateMonteCarlo(void* quadrant);

#if 0
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
#endif

void* simulateMonteCarlo(void* quadrant)
{
    float x[NUM_MAX], y[NUM_MAX];
    int index = *(int*)quadrant - 1;
    int quad[4][2] = { {0, 0}, {0, -1}, {-1, -1}, {-1, 0} };

    generateRandBetween(quad[index][X], quad[index][X] + 1, NUM_MAX, x);
    generateRandBetween(quad[index][Y], quad[index][Y] + 1, NUM_MAX, y);

    for (int i=0; i<NUM_MAX; i++) {
        if(x[i]*x[i] + y[i]*y[i] <= 1) count[index]++;
    }
    
    pthread_exit(NULL);
}