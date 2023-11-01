#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* 
	  Programmer  : Beyza Nur Yıldırım
    Date        : 01.10.2023
    Last Update : 01.10.2023
*/

/* This a program to implement stack using linked list */

typedef struct StackNode {
    int data;
    struct StackNode* next;
}Stack;

//create node
Stack* createNode(Stack* root);

//push 
void push(Stack** root, int data);

//pop
int pop(Stack** root);

int main(void) {
    Stack* root = NULL;
    int result, data, choice;

    printf("Welcome to linked list implememntation of stacks.\n1. Push\n2. Pop\n3. Exit\n");
    while (1) {
        printf("Enter your choice[1-3]: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: 
            printf("Enter data to push into stack: ");
            scanf("%d", &data);
            push(&root, data);
            break;
        case 2:
            result = pop(&root);
            if (result == INT_MIN)
                printf("Stack Underflow! Stack is already empty.\n");
            else
                printf("%d poppped.\n", result);
            break;
        case 3: 
            exit(0);
            break;
        default:
            printf("Wrong choice.\n");
            break;
        }
    }
    return (0);
}
Stack* createNode(Stack* root) {
    Stack * newNode = (Stack*)malloc(sizeof(Stack));

    //stack is empty
    if (root == NULL) {
        newNode->next = NULL;
    }
    else {
        newNode->next = root;
    }
    root = newNode;

    return root;
}
void push(Stack** root, int data) {
    *root = createNode(*root);

    (*root)->data = data;
    printf("%d pushed to stack.\n", data);
}
int pop(Stack** root) {

    if (*root == NULL)
        return INT_MIN;

    Stack* temp = *root;
    int data = temp->data;

    (*root) = (*root)->next;
    temp->next = NULL;
    free(temp);

    return data;
}
