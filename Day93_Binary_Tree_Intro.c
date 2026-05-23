#include <stdio.h>
#include <stdlib.h>

// node structure
struct Node {

    int data;

    struct Node* left;
    struct Node* right;
};

// create new node
struct Node* createNode(int value) {

    struct Node* newNode =
        (struct Node*) malloc(sizeof(struct Node));

    newNode->data = value;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main() {

    // create root
    struct Node* root = createNode(10);

    // left child
    root->left = createNode(20);

    // right child
    root->right = createNode(30);

    // more nodes
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    printf("Root Node: %d\n", root->data);

    printf("Left Child: %d\n", root->left->data);

    printf("Right Child: %d\n", root->right->data);

    return 0;
}