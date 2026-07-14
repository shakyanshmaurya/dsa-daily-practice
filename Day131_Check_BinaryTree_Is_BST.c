#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int isBST(struct Node *root, int min, int max) {

    if(root == NULL)
        return 1;

    if(root->data <= min || root->data >= max)
        return 0;

    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

int main() {

    struct Node *root = createNode(10);

    root->left = createNode(5);
    root->right = createNode(20);

    root->left->left = createNode(2);
    root->left->right = createNode(8);

    root->right->left = createNode(15);
    root->right->right = createNode(30);

    if(isBST(root, INT_MIN, INT_MAX))
        printf("Valid BST");
    else
        printf("Not a BST");

    return 0;
}