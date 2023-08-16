#include <stdio.h>
#define STACK_SIZE 10

void push(int item);
int pop();
void printStack();

int stack[STACK_SIZE];
int actual_size = 0;

int main(void)
{
    printStack();
    push(10);
    push(20);
    push(30);
    printStack();
    pop();
    pop();
    printStack();
    push(40);
    push(50);
    printStack();
    pop();
    pop();
    pop();
    printStack();
    return 0;
}

void push(int item)
{
    if(actual_size < STACK_SIZE) {
        stack[actual_size++] = item;
    } else {
        printf("Cannot push item: stack full\n");
    }
}
int pop()
{
    int result = -1;
    if(actual_size > 0) {
        result = stack[actual_size-1];
        actual_size--;
        printf("POP: %d\n", result);
    }
    return result;
}

void printStack()
{
    for(int i = 0; i < actual_size; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}