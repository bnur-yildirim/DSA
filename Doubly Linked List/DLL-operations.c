#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* Programmer  : Beyza Nur Yıldırım
   Date        : 15.10.2023
   Last Update : 19.10.2023
*/

/* This is a program to practice doubly linked lists */

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node and add it to the beginning of the list
void createList(struct Node** head, struct Node** last);

// Function to display the doubly linked list from the beginning
void displayFirst(struct Node* head);

// Function to display the doubly linked list from the end (in reverse)
void displayLast(struct Node* last);

// Function to free the memory used by the linked list
void freeList(struct Node* head);

// Function to delete a node from the doubly linked list from any position
void deleteNode(struct Node** head, struct Node** last);

int main(void) {
    int count;
    struct Node* head = NULL;
    struct Node* last = NULL;

    printf("Enter number of nodes to be created: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        createList(&head, &last);
    }

    displayFirst(head);
    displayLast(last);

    deleteNode(&head, &last);

    displayFirst(head);

    // Free the allocated memory
    freeList(head);

    return 0;
}

// Function to create a new node and add it to the beginning of the list
void createList(struct Node** head, struct Node** last) {
    int data;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed for the new node.\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &data);

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        *last = newNode;
    }
    else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to display the doubly linked list from the beginning
void displayFirst(struct Node* head) {
    struct Node* curr = head;
    if (curr == NULL) {
        printf("List from forward is empty.\n");
        return;
    }
    printf("List from forward: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Function to display the doubly linked list from the end (in reverse)
void displayLast(struct Node* last) {
    struct Node* curr = last;
    if (curr == NULL) {
        printf("List from backward is empty.\n");
        return;
    }
    printf("List from backward: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
}

// Function to free the memory used by the linked list
void freeList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    printf("Memory deallocated successfully.\n");
}
// Function to delete a node from the doubly linked list from any position
void deleteNode(struct Node** head, struct Node** last) {
    int num;
    struct Node* curr = *head;
    
    if (*head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    printf("Enter the position you want to delete: ");
    scanf("%d", &num);
    
    for (int i = 1; i < num; i++) {
        curr = curr->next;
    }
    curr->data = NULL;

    if (curr == (*head)) {
        curr->next->prev = NULL;
        *head = curr->next;
        curr->next = NULL;
    }
    else if (curr == (*last)) {
        curr->prev->next = NULL;
        *last = curr->prev;
        curr->prev = NULL;
    }
    else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->prev = NULL;
        curr->next = NULL;
    }
    free(curr);
    printf("Element in position %d deleted succesfully.\n", num);
}
