#include <stdio.h>
#include <limits.h>

/* 
	Programmer  : Beyza Nur Yıldırım
    Date        : 28.10.2023
    Last Update : 28.10.2023
*/

/* This a program to implement stack using array */

#define MAX 13 //maximum stack size

int stack[MAX], top = -1; //stack is empty top is full

void push(int data);  //insert element to the top of the stack
int pop(void);       //remove top value and return new top 
int isEmpty(void);   // return 1 if stack is empty, otherwhise 0
int isFull(void);    // return 1 if stack is full, otherwhise 0
void printStack(void);  //print all the elements in the stack;
int main(void) {
	int option, data;
	printf("Welcome to stack program.\n1. Push an element to the stack.\n");
	printf("2. Delete the element from the top.\n3. Display size of the stack.\n");
	printf("4. Display all elements in the stack.\n5. Exit.\n");
	while (1) {
		printf("Option[1-5]: ");
		scanf("%d", &option);

		switch (option) {
		case 1:
			printf("Enter data to push into stack: ");
			scanf("%d", &data);

			push(data);
			break;
		case 2:
			data = pop();
			if (data != INT_MIN)
				printf("Element at the top is %d.\n", data);
			break;
		case 3:
			printf("Size of the stack is %d.\n", top + 1);
			break;
		case 4:
			printf("All elements in the stack are: ");
			printStack();
			break;
		case 5:
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
int isEmpty(void) {
	if (top == -1)
		return 1;
	else
		return 0;
}
int isFull(void) {
	if (top == MAX - 1)
		return 1;
	else
		return 0;
}
void push(int data) {
	if (!(isFull())) {
		stack[++top] = data;
		printf("%d pushed to stack.\n", data);
	}
	else {
		printf("Stack Overflow!\nStack is already full.\n");
	}
}
int pop(void) {
	if (!(isEmpty())) {
		printf("%d removed from stack.\n", stack[top--]);
		return stack[top];
	}
	else {
		printf("Stack Underflow!\nStack is already empty.\n");
		return INT_MIN;
	}
}
void printStack(void) {
	int i = 0;
	while (i <= top) {
		printf("%d ", stack[i]);
		i++;
	}
	printf("\n");
}
