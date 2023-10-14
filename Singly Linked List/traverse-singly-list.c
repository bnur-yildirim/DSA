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

unsigned short int count_of_nodes(struct Node* head);   //function to traverse list

int main(void)
{
	struct Node* head;            //head pointer
	// allocate memory for the node
	head = (struct Node*)malloc(sizeof(struct Node));

	head->data = 45;     // first member in the list is 45
	head->next = NULL;   // there is only one node so it points to null

	//creating second node
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = 98;
	current->next = NULL;           //now there are two sepeate nodes

	//connecting nodes
	head->next = current;

	//creating third node
	current = (struct Node*)malloc(sizeof(struct Node));
	current->data = 3;
	current->next = NULL;

	//connecting nodes
	head->next->next = current;

	//print list
	current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}

	printf("\nList has %hu elements.\n", count_of_nodes(head));

	return (0);
}
unsigned short int count_of_nodes(struct Node* head)
{
	unsigned short int count = 0;  // var to count number of nodes in the list

	//if list does not exist
	if (head == NULL)
	{
		printf("List doesn't exist.\n");
		return(-1);
	}
	//temporary node to traverse list
	struct Node* temp = head;
	//if temp == NULL we are at the end of the list
	while (temp != NULL)
	{
		count++;       //increment count with every node
		temp = temp->next;    //make temp point to next node
	}
	return count;
}
