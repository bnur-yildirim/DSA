#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* 
	Programmer  : Beyza Nur Yıldırım
    Date        : 28.10.2023
    Last Update : 28.10.2023
*/

/* This a program to implement stack using array in another way */

typedef struct Stack {
	int top;          // to store index of top value
	unsigned size;   // maximum size of the stack
	int* stack;     // array to store integer stack
}Stack;

Stack* createStack(unsigned size);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
int peek(Stack* stack);       // return value on the top without removing it
void push(Stack* stack, int value);
int pop(Stack* stack);

int main(void) {
	int size, option, data, result;
	printf("This program will create a stack.\nEnter size for the stack: ");
	scanf("%d", &size);

	Stack* stack = createStack(size);

	printf("1. Push an element into the stack.\n2. Pop an element from the stack.\n");
	printf("3. Display size of the stack.\n4. Exit.\n");

	while (1) {
		printf("Enter option[1-4]: ");
		scanf("%d", &option);

		switch (option) {
		case 1:
			printf("Enter value to push into the stack: ");
			scanf("%d", &data);
			push(stack, data);
			break;
		case 2:
			result = pop(stack);
			if (result == INT_MIN)
				printf("Error: Stack Underflow!\n");
			else
				printf("%d popped from stack.\n", result);
			break;
		case 3:
			printf("Size is: %d.\n", stack->top + 1);
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Wrong option.\n");
			exit(-1);
			break;
		}
	}
	return 0;
}
//stack is empty when top is -1
int isEmpty(Stack* stack) {
	return stack->top == -1;
}
//stack is full when top is size -1
int isFull(Stack* stack) {
	return stack->top == stack->size - 1;
}
Stack* createStack(unsigned size) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->size = size;
	stack->top = -1;     //stack is empty
	stack->stack = (int*)malloc(stack->size * sizeof(int));

	printf("Stack created succesfully.\n");
	return stack;
}
// return value at the top
int peek(Stack* stack) {
	if (isEmpty(stack))
		return INT_MIN;
	return stack->stack[stack->top];
}
void push(Stack* stack, int value) {
	if (isFull(stack)) {
		printf("Error: Stack Overflow!\n");
		return;
	}
	stack->stack[++stack->top] = value;
	printf("%d pushed into stack.\n", value);
}
int pop(Stack* stack) {
	if (isEmpty(stack))
		return INT_MIN;
	return stack->stack[stack->top--];
}
