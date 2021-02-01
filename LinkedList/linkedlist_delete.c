// Deleting a Node from nth position - LinkedList
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

void deleteNode(int n){
    int i;
    struct Node* temp1 = head;

    // If we are deleting the first node
    if (n==1){
        head = temp1->next;
        free(temp1);
    }
    // Otherwise
    else{
        // This will make temp1 point to (n-1)th node 
        for (i=0; i<n-2; i++){
            temp1 = temp1->next;
        }
        struct Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
    }
}

int main(){
    head = NULL;
    // Insert some nodes and display the linkedlist
    insertNode(10, 1); // List: 10
    insertNode(20, 2); // List: 10, 20
    insertNode(30, 3); // List: 10, 20, 30
    insertNode(40, 4); // List: 10, 20, 30, 40
    printf("\nBefore Deleting a Node.\n");
    displayLinkedList();
    printf("\nAfter Deleting a Node:\n");
    // Delete a node and then display the linkedlist again
    deleteNode(3); // Should delete "30", List should now be: 10, 20, 40
    displayLinkedList();
}