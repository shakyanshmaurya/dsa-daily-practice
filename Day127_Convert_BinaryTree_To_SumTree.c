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

int toSumTree(struct Node *root) {

    if(root == NULL)
        return 0;

    int oldValue = root->data;

    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);

    root->data = leftSum + rightSum;

    return oldValue + root->data;
}

void inorder(struct Node *root) {

    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {

    struct Node *root = createNode(10);

    root->left = createNode(5);
    root->right = createNode(3);

    root->left->left = createNode(2);
    root->left->right = createNode(1);

    printf("Original Tree (Inorder):\n");
    inorder(root);

    toSumTree(root);

    printf("\nSum Tree (Inorder):\n");
    inorder(root);

    return 0;
}