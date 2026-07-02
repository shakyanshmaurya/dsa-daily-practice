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

struct Node* LCA(struct Node *root, int n1, int n2) {

    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct Node *left =
        LCA(root->left, n1, n2);

    struct Node *right =
        LCA(root->right, n1, n2);

    if(left && right)
        return root;

    if(left)
        return left;

    return right;
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    struct Node *ans =
        LCA(root, 4, 5);

    printf("LCA = %d", ans->data);

    return 0;
}