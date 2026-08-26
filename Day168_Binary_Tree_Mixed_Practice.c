#include <stdio.h>
#include <stdlib.h>

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

/* 1. Height of Binary Tree */

int height(struct Node *root) {

    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

/* 2. Count Leaf Nodes */

int countLeaves(struct Node *root) {

    if(root == NULL)
        return 0;

    if(root->left == NULL &&
       root->right == NULL)
        return 1;

    return countLeaves(root->left) +
           countLeaves(root->right);
}

/* 3. Sum of All Nodes */

int sumNodes(struct Node *root) {

    if(root == NULL)
        return 0;

    return root->data +
           sumNodes(root->left) +
           sumNodes(root->right);
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Height = %d\n", height(root));

    printf("Leaf Nodes = %d\n", countLeaves(root));

    printf("Sum of Nodes = %d\n", sumNodes(root));

    return 0;
}