#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>


/* 
	Programmer  : Beyza Nur Yıldırım
    Date        : 01.11.2023
    Last Update : 01.11.2023
*/


#define MAX 25
int stack[MAX];
int top = -1;

void push(int data);

int pop();

int main() {
    int size,data;

    printf("Enter size for array stack: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter data: ");
        scanf("%d", &data);
        push(data);
    }
    printf("Reversed array is: ");

    for (int i = 0; i < size; i++) {
       
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}
void push(int data) {
    if (top == MAX - 1) {
        printf("stack overflow.\n");
        return;
    }
    stack[++top] = data;
}
int pop() {
    if (top == -1) {
        printf("stack underflow.\n");
        return INT_MIN;
    }
    return stack[top--];
}
