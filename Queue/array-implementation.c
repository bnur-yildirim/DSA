#include <stdio.h>
#include <limits.h>

/*
	Programmer  : Beyza Nur Yıldırım
	Date        : 04.11.2023
	Last Update : 05.11.2023
*/

#define CAPACITY 25
int queue[CAPACITY];
int front = 0;
int size = 0;
int rear = CAPACITY - 1;

void enqueue(int data);     // insert data
int dequeue(void);          // remove data
int isEmpty();				// return 1 if empty, otherwise 0
int isFull();				// return 1 if full, otherwise 0
void menu();				// print options menu
int frontValue();			// return element at the front without removing it
int rearValue();			// return element at the end without removing it


int main() {
	unsigned short choice;
	int data, result;

	menu();

	while (1) {
		printf("\nEnter choice[1-8]: ");
		scanf("%hu", &choice);

		switch (choice) {
		case 1:
			printf("Enter data to be inserted: ");
			scanf("%d", &data);

			enqueue(data);
			break;
		case 2:
			result = dequeue();

			if (result == INT_MIN)
				printf("Queue is already empty.\n");
			else
				printf("%d removed from queue.\n", result);
			break;
		case 3:
			if (isFull())
				printf("Queue is full.\n");
			else
				printf("Queue is NOT full.\n");
			break;
		case 4:
			if (isEmpty())
				printf("Queue is empty.\n");
			else
				printf("Queue is NOT empty.\n");
			break;
		case 5:
			result = frontValue();
			if (result == INT_MIN)
				printf("List is empty.\n");
			else
				printf("Element at the front is: %d.\n", result);
			break;
		case 6:
			result = rearValue();
			if (result == INT_MIN)
				printf("List is empty.\n");
			else
				printf("Element at the end is: %d.\n", result);
			break;
		case 7:
			menu();
			break;
		case 8:
			printf("Size of the queue is: %d.\n", size);
			break;
		case 9:
			exit(0);
			break;
		default:
			printf("Wrong choice.\n");
			exit(-1);
			break;
		}
	}

	return 0;
}
void enqueue(int data) {
	if (isFull()) {
		printf("stack overflow.\n");
		return;
	}
	rear = (rear + 1) % CAPACITY;
	queue[rear] = data;
	size++;
}
int dequeue(void) {
	if (isEmpty())
		return INT_MIN;
	int value = queue[front];
	front = (front + 1) % CAPACITY;
	size--;
	return value;
}
int isEmpty() {
	return size == 0;
}
int isFull() {
	return size == CAPACITY;
}
void menu() {
	printf("1. Insert an element.\n2. Remove an element.\n3. Check if queue is full.\n");
	printf("4. Check if queue is empty.\n5. Display the element at the front without removing.\n");
	printf("6. Display the element at the end without removing it.\n7. Display menu.\n");
	printf("8. Display size of the queue.\n9. Exit.\n");
}
int frontValue() {
	if (isEmpty())
		return INT_MIN;
	else
		return queue[front];
}
int rearValue() {
	if (isEmpty())
		return INT_MIN;
	else
		return queue[rear];
}
