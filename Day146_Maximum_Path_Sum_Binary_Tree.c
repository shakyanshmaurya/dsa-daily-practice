#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSum = -1000000;

int maxPath(struct Node *root) {

    if(root == NULL)
        return 0;

    int left = max(0, maxPath(root->left));
    int right = max(0, maxPath(root->right));

    int current = root->data + left + right;

    if(current > maxSum)
        maxSum = current;

    return root->data + max(left, right);
}

int main() {

    struct Node *root = createNode(10);

    root->left = createNode(2);
    root->right = createNode(10);

    root->left->left = createNode(20);
    root->left->right = createNode(1);

    root->right->right = createNode(-25);
    root->right->right->left = createNode(3);
    root->right->right->right = createNode(4);

    maxPath(root);

    printf("Maximum Path Sum = %d", maxSum);

    return 0;
}