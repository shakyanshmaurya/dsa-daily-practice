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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxRootToLeafSum(struct Node *root) {

    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return root->data;

    int leftSum = maxRootToLeafSum(root->left);
    int rightSum = maxRootToLeafSum(root->right);

    return root->data + max(leftSum, rightSum);
}

int main() {

    struct Node *root = createNode(10);

    root->left = createNode(8);
    root->right = createNode(2);

    root->left->left = createNode(3);
    root->left->right = createNode(5);

    root->right->right = createNode(6);

    printf("Maximum Root-to-Leaf Sum = %d",
           maxRootToLeafSum(root));

    return 0;
}