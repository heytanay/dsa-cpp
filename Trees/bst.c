#include <stdio.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}

// Root Node Pointer (not the root node itself)
struct Node* rootPtr = NULL;

// Function to create a new node
struct Node* makeNewNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;    
    return newNode;
}

void insertNodeTree(int data){
    if (rootPtr == NULL){
        rootPtr = makeNewNode(data);
    }
    else if (data <= rootPtr->data){
        rootPtr->left = insertNodeTree(rootPtr->left, data);
    }
    else{
        rootPtr->right = insertNodeTree(rootPtr->right, data);
    }
    return rootPtr;
}

int main(){
    insertNodeTree(rootPtr, 50);
    insertNodeTree(rootPtr, 20);
    insertNodeTree(rootPtr, 15);
    insertNodeTree(rootPtr, 10);
}