#include <stdio.h>
#include <stdlib.h>

#define INPUT_MAX 1024                  // Mximum number of elements
#define INPUT_FILE_NAME "1_input.txt"     // Input file containing input data to sort (+ the number of elements)

void swapVariable(int* a, int* b);
void bubbleSort(int dataTotal, int* dataArray);
int readInput(int* buffer);

int main(void)
{

    int arr[9];
    readInput(arr);

    bubbleSort(sizeof(arr)/sizeof(arr[0]), arr);
    
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Read input data from a file and write the data into buffer
int readInput(int* buffer)
{
    FILE* fd;    
    int dataTotal;
    int i;

    fd = fopen(INPUT_FILE_NAME, "r");
	if (fd == NULL)	{
		printf("Error: Failed to open '%s'.\n", INPUT_FILE_NAME);
		return -1;
	}

	/* read input file to get task parameters */
	fscanf(fd, "%d \n", &dataTotal);
    if (dataTotal > INPUT_MAX) {
        printf("The number of elements exceeds the limit %d.\n", INPUT_MAX);
        return -1;
    }

	for (i = 0; i < dataTotal; i++) {
		fscanf(fd, "%d ", &buffer[i]);
    }
   
    return dataTotal;
}

void swapVariable(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int dataTotal, int* dataArray)
{
    
    for(int i = 1; i < dataTotal; i++) {
        for(int j = 1; j <= dataTotal-i; j++) {
            if(dataArray[j-1] > dataArray[j]) {
                swapVariable(&dataArray[j-1], &dataArray[j]);
            }
        }
        
    }
}