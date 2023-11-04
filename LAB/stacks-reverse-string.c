#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>


/* 
	Programmer  : Beyza Nur Yıldırım
    Date        : 01.11.2023
    Last Update : 01.11.2023
*/


 struct StackNode {
    char data;
    struct StackNode* next;
};

 struct StackNode* newNode(char data) {
     struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));

     stackNode->data = data;
     stackNode->next = NULL;

     return stackNode;
 }
 int isEmpty(struct StackNode* root) {
     return !root;
 }
 void push(struct StackNode** root, char data) {
     struct StackNode* stackNode = newNode(data);
     stackNode->next = *root;
     *root = stackNode;
 }
 int pop(struct StackNode** root) {
     if (isEmpty(*root))
         printf("Stack owerflow. \n");
     struct StackNode* temp = *root;
     *root = (*root)->next;
     char popped = temp->data;
     free(temp);

     return popped;
 }
 void printStack(struct StackNode* root) {

     struct StackNode* curr = root;
     printf("%d",root);
     while (curr != NULL) {
         printf("%c", curr->data);
         curr = curr->next;
     }
     printf("\n");
 }

int main(void) {
    struct StackNode* root = NULL;

    char name[19] = "Beyza Nur Yildirim";

    for (int i = 0; i < 18; i++) {
        push(&root, name[i]);
    }
    for (int i = 0; i < 18; i++) {
        printf("%c", pop(&root));
    }
    
    return 0;
}
