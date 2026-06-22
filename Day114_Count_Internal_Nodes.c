#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {

    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int countInternalNodes(struct Node* root) {

    if(root == NULL)
        return 0;

    if(root->left == NULL &&
       root->right == NULL)
        return 0;

    return 1
         + countInternalNodes(root->left)
         + countInternalNodes(root->right);
}

int main() {

    struct Node* root =
        createNode(1);

    root->left =
        createNode(2);

    root->right =
        createNode(3);

    root->left->left =
        createNode(4);

    root->left->right =
        createNode(5);

    printf("Internal Nodes = %d",
           countInternalNodes(root));

    return 0;
}