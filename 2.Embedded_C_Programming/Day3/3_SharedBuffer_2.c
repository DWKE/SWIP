#include <stdio.h>
#include <pthread.h>

int glob;


void* incrementGLobVar(void* arg);

#if 0
int main(void)
{
    int i;
    pthread_t threads[5];
    int threadNumber[5] = {1, 2, 3, 4, 5};

    for(i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, incrementGLobVar, &threadNumber[i]);
    }

    for (i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
#endif

void* incrementGLobVar(void* threadNumber)
{
    int i;
    for( i=0; i<5; i++) {
        printf("Thread %d: %d\n", *(int*)threadNumber, glob++);
    }

    pthread_exit(NULL);
}