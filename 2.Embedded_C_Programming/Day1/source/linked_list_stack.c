#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_FILE_NAME "input_linked_list_stack.txt"    // Input file containing input data (+ the number of operations)

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;           // Pointer to the top of stack

// Insert item into the stack
void push(int item) 
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

// Get the top element from the stack
int pop() 
{
    int dataTop;

    if (top == NULL) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }
    
    dataTop = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);

    return dataTop;
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
    while (top != NULL) {
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}