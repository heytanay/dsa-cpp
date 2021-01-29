#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void insertAtStart(int x){
    // Allocate the memory for the node
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    // Inser the data and link to the new node
    temp->data = x;
    temp->next = head;
    head = temp;
}

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
}

int main(){
    int n, i, currentInput;
    head = NULL;
    printf("How many numbers?\n");
    scanf("%d", &n);

    for (i=0; i<n; i++){
        printf("\nEnter the number at %d position: ", i);
        scanf("%d", &currentInput);
        insertAtStart(currentInput);
        printf("\nAll elements in the linked list:\n");
        displayLinkedList();
    }
}