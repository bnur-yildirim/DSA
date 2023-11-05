#include <stdio.h>
#include <limits.h>

/*
	Programmer  : Beyza Nur Yıldırım
	Date        : 04.11.2023
	Last Update : 05.11.2023
*/

#define CAPACITY 20
int queue[CAPACITY];
int front = 0;
int size = 0;
int rear = CAPACITY - 1;

void enqueue(int data);
int dequeue(void);

int main() {

	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	enqueue(60);

	for (int i = front; i < size; i++) {
		printf("%d ", queue[i]);
	}

	int result = dequeue();

	if (result == INT_MIN)
		printf("Queue is already empty.\n");
	else
		printf("%d removed from queue.\n", result);

	return 0;
}
void enqueue(int data) {
	if (size == CAPACITY) {
		printf("stack overflow.\n");
		return;
	}
	rear = (rear + 1) % CAPACITY;
	queue[rear] = data;
	size++;
}
int dequeue(void) {
	if (size == 0)
		return INT_MIN;
	int value = queue[front];
	front = (front + 1) % CAPACITY;
	size--;
	return value;
}
