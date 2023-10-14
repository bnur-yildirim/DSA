#include <stdio.h>
#include <stdlib.h>

/*	Programmer   : Beyza Nur Yıldırım
	Date         : 13.10.2023
	Last Updated : 14.10.2023
*/

/* C program to traverse singly linked list */

struct Node {
	int data;
	struct Node* next;				//pointer to the next node
};

struct Node* addNode(struct Node *head,int n);
void print(struct Node* head);

int main(void)
{
	struct Node* head = NULL;

	head = addNode(head, 5);
	head = addNode(head, 24);

	print(head);
	
	return (0);
}
void print(struct Node* head)
{
	struct Node* current = head;
	
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}
struct Node* addNode(struct Node* head,int n)
{
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	if (current == NULL) {
		return NULL;
	}
	if (head == NULL)
	{
		current->data = n;
		head = current;
		current->next = NULL;
	}
	else
	{
		current->data = n;
		current->next = head;
	}
	return current;
}
