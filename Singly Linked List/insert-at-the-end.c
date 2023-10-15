#include <stdio.h>
#include <stdlib.h>

/*	Programmer  : Beyza Nur Yıldırım
	Date        : 15.10.2023
	Last Update : 15.10.2023
*/

/* program to create list and insert a node at the end */

struct Node {
	int data;
	struct Node* next;
};

void createL(struct Node** head);

void printL(struct Node* head);

int main(void) {
	int count;
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head = NULL;

	printf("Enter number of nodes to be created: ");
	scanf("%d", &count);
    
	for (int i = 0; i < count; i++) {
		createL(&head);
	}
	printL(head);
	return 0;
}
void createL(struct Node** head) {
	int num;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	struct Node* curr = *head;   //current node
	struct Node* prev = *head;   //previous node

	if (newNode == NULL)
		return(NULL);
	
	printf("Enter data: ");
	scanf("%d", &num);

	newNode->data = num;
	newNode->next = NULL;

	if (*head == NULL) {       //if list does not exist
		*head = newNode;
	}
	else {                     //list exists          
		while (curr->next != NULL && curr != NULL) {      //find the last node
			prev = curr;
			curr = curr->next;
		}
		curr->next = newNode;
	}
}
void printL(struct Node* head) {
	struct Node* temp = head;
	if (temp == NULL)
		return NULL;

	printf("List is: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
