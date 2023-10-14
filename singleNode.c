#include <stdio.h>
#include <stdlib.h>

/*	Programmer   : Beyza Nur Yıldırım
	Date         : 13.10.2023
	Last Updated : 14.10.2023
*/

/* C program to create one node linked list */

struct Node {
	int data;        
	struct Node* next;				//pointer to the next node
};

int main(void)
{
	struct Node* head;            //head pointer
	// allocate memory for the node
	head = (struct Node*)malloc(sizeof(struct Node));
	
	head->data = 45;     // first member in the list is 45
	head->next = NULL;   // there is only one node so it points to null

	//printing list
	printf("%d ", head->data);

	return (0);
}
