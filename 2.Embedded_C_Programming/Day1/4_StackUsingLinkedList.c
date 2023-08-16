#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(int item);
int pop();
void printStack();

Node* head;

int main(void)
{
    printStack();
    push(10);
    push(20);
    push(30);
    printStack();
    printf("POP: %d\n", pop());
    printf("POP: %d\n", pop());
    printStack();
    push(40);
    push(50);
    printStack();
    printf("POP: %d\n", pop());
    printf("POP: %d\n", pop());
    printf("POP: %d\n", pop());
    printStack();
    return 0;
}

void push(int item)
{
    Node* new_node = malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;

    if(head) { // 스택의 길이가 1 이상인 경우
        Node* iter = head;

        while(iter->next) {
            iter = iter->next;
        }

        iter->next = new_node;
    } else { // 스택의 길이가 0인 경우
        head = new_node;
    }

    
}

int pop()
{
    int result = -1;
    if(head->next) { // 스택의 길이가 2 이상인 경우
        Node* iter = head;
        while(iter->next->next) {
            iter = iter->next;
        }
        result = iter->next->data;
        free(iter->next);
        iter->next = NULL;
    } else if(head) { // 스택의 길이가 1인 경우
        result = head->data;
        free(head);
        head = NULL;
    } else { // 스택의 길이가 0인 경우
        // Pass
    }
    return result;
}

void printStack()
{
    Node* iter = head;
    if(head) {
        printf("Data: ");
        while(iter) {
            printf("%d ", iter->data);
            iter = iter->next;
        }
        printf("\n");
    } else {
        printf("Empty\n");
    }

}