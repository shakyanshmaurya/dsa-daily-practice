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

// Sum Function
int sumNodes(struct Node* root) {

    if(root == NULL)
        return 0;

    return root->data
         + sumNodes(root->left)
         + sumNodes(root->right);
}

int main() {

    struct Node* root = createNode(10);

    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(40);
    root->left->right = createNode(50);

    printf("Sum of Nodes = %d",
           sumNodes(root));

    return 0;
}