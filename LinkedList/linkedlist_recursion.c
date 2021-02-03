#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// Print linkedlist using recursion
void printLinkedList(struct Node* p){
    if (p == NULL) return;
    printf("%d ", p->data);
    printLinkedList(p->next);
};

// Recursive Print linkedlist using recursion
void reversePrintLinkedList(struct Node* p){
    if (p == NULL) return;
    printLinkedList(p->next);
    printf("%d ", p->data);
};


struct Node* insertNode(struct Node* head, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL){
        head = temp;
    }
    else{
        struct Node* temp1 = head;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
};

int main(){
    struct Node* head = NULL;
    head = insertNode(head, 15);
    head = insertNode(head, 25);
    head = insertNode(head, 35);
    head = insertNode(head, 45);
    printLinkedList(head);
    printf("\n");
    reversePrintLinkedList(head);
}