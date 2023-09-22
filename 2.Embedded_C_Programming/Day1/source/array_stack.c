#include <stdio.h>
#include <string.h>

#define INPUT_FILE_NAME "input_array_stack.txt"     // Input file containing input data (+ the number of operations)
#define ARRAY_MAX 1024                              // Mximum size of array

int stack[ARRAY_MAX];           // Stack implemented as an array
int top = -1;                   // Index to the top of stack

// Insert item into the stack
void push(int item) 
{
    if (top < ARRAY_MAX) {
        stack[++top] = item;
    }
    else {
        printf("Stack is full.\n");
    }    
}

// Get the top element from the stack
int pop() 
{
    if (top > -1) {
        return stack[top--];
    }
    else {
        printf("Stack is empty\n");
        return -1;
    }    
}

int readInput()
{
    FILE* fd;    
    int operationTotal;
    char buffer[8];
    int operand;
    int poppedData;
    int i;

    fd = fopen(INPUT_FILE_NAME, "r");
	if (fd == NULL)	{
		printf("Error: Failed to open '%s'.\n", INPUT_FILE_NAME);
		return -1;
	}

	/* read input file */
	fscanf(fd, "%d \n", &operationTotal);
    
	for (i = 0; i < operationTotal; i++) {
        fscanf(fd, "%s", buffer);
        fscanf(fd, "%d ", &operand);
        if (strcmp(buffer, "push") == 0)
            push(operand);
        else
            poppedData = pop();
    }
   
    return operationTotal;
}

int main() 
{
    int ret;

    readInput();

    printf("The remaining elements in the stack: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}