#include <stdio.h>
#include <stdlib.h>

/*	Programmer  : Beyza Nur Yıldırım
	Date        : 15.10.2023
	Last Update : 15.10.2023
*/



struct Node {
	int data;
	struct Node* next;
};

void createL(struct Node** head);

void printL(struct Node* head);

void insertNode(struct Node** head);

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
	insertNode(&head);
	printL(head);

	return 0;
}
//create list with insertion at the end
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
	printf("\n");
}
//insert node at any position
void insertNode(struct Node** head) {
	int position, num, count = 1;

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* curr = *head;     //current node
	struct Node* prev = *head;    //previous node
	struct Node* countP = *head;   //to count number of elements in the list

	if (newNode == NULL)
		return NULL;

	printf("We will insert a node.\nEnter data: ");
	scanf("%d", &num);

	newNode->data = num;    //fill data for the new node

	printf("Enter position you want to insert: ");
	scanf("%d", &position);
	//itarate prev to position we want to insert 
	for (int i = 1; curr->next!=NULL && i < position; i++) {
		prev = curr;
		curr = curr->next;
	}
	while (countP->next != NULL) {
		count++;
		countP = countP->next;
	}

	if (position==1) {
		//insert at the beginning
		newNode->next = *head;
		*head = newNode;
	}
	else {
		
		//insert at the end
		if (position==count+1) {
			newNode->next = NULL;
			curr->next = newNode;
		}
		//insert at middle
		else {   
			newNode->next = prev->next;
			prev->next = newNode;
		}	
	}
}
