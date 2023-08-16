#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024                  // Mximum number of elements
#define INPUT_FILE_NAME "6_input.txt"     // Input file containing input data to sort (+ the number of elements)

void swap(int* a, int* b);
int readInput(int inputData[][MAX_SIZE], int* rowSize, int *columnSize);
void generateMatrixTranspose(int rowSize, int columnSize, int matrix[][MAX_SIZE]);
void printMatrix(int matrix[][MAX_SIZE], int rowSize, int colSize);

int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE] = { 0 };
    int rowSize;
    int colSize;

    readInput(matrix, &rowSize, &colSize);
    printf("Input Matrix:\n");
    printMatrix(matrix, rowSize, colSize);

    generateMatrixTranspose(rowSize, colSize, matrix);
    swap(&rowSize, &colSize);
    printf("Transposed Matrix:\n");
    printMatrix(matrix, rowSize, colSize);
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int readInput(int inputData[][MAX_SIZE], int* rowSize, int *columnSize)
{
    FILE* fd;    
    int result = 0;

    fd = fopen(INPUT_FILE_NAME, "r");
	if (fd == NULL)	{
		printf("Error: Failed to open '%s'.\n", INPUT_FILE_NAME);
		result = -1;
	}
    else {
        /* read input file to get task parameters */
        fscanf(fd, "%d x %d\n", rowSize, columnSize);

        if (*rowSize > MAX_SIZE || *columnSize > MAX_SIZE) {
            printf("The number of elements exceeds the limit %d.\n", MAX_SIZE);
            result = -1;
        }
        else {
            for (int i = 0; i < *rowSize; i++) {
                for(int j = 0; j < *columnSize; j++) {
                    fscanf(fd, "%d ", &inputData[i][j]);
                }
            }
        }
    }

    return result;
}

void generateMatrixTranspose(int rowSize, int columnSize, int matrix[][MAX_SIZE])
{
    int size = rowSize >= columnSize ? rowSize : columnSize;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}

void printMatrix(int matrix[][MAX_SIZE], int rowSize, int colSize)
{
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}