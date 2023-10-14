#include <stdio.h>
#include <stdlib.h>

/*	Programmer   : Beyza Nur Yıldırım
	Date         : 14.10.2023
	Last Updated : 14.10.2023
*/

/* C program to create two node linked list */

struct Node {
	int data;        
	struct Node* next;				//pointer to the next node
};

int main(void)
{
	// creating first node pointer
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = 45;
	head->next = NULL;

	//creating second node
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = 98;
	current->next = NULL;

	//connecting nodes
	head->next = current;

	return (0);
}
