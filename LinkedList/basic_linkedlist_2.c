// Inserting a Node at nth position
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void insertNode(int data, int n){
    int i;
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;

    // If the list is empty, just insert at beginning and change some references
    if (n == 1){
        temp1->next = head;
        head = temp1;
        return;
    }

    // If not then go the the required position in the memory and some the same as above
    struct Node* temp2 = head;
    for (i=0; i<n-2; i++){
        temp2 = temp2->next;
    }
    // After running above loop, the temp2 has arrived at the required position, so proceed.
    temp1->next = temp2->next;
    temp2->next = temp1;
};

void displayLinkedList(){
    struct Node* temp = head;
    while (temp != NULL){
        if (temp->next == NULL){
            printf("%d", temp->data);
        }
        else{
            printf("%d --> ", temp->data);
        }
        temp = temp->next;
    }
    printf("\n");
};

int main(){
    head = NULL;
    insertNode(50, 1); // List: 50
    insertNode(40, 2); // List: 50, 40
    insertNode(20, 3); // List: 50, 40, 20
    insertNode(10, 2); // List: 50, 10, 40, 20
    displayLinkedList();
}