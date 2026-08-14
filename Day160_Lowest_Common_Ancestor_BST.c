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

struct Node* insert(struct Node *root, int value) {

    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct Node* LCA(struct Node *root, int p, int q) {

    if(root == NULL)
        return NULL;

    // Both values are smaller
    if(p < root->data && q < root->data)
        return LCA(root->left, p, q);

    // Both values are larger
    if(p > root->data && q > root->data)
        return LCA(root->right, p, q);

    // They split at this node
    return root;
}

int main() {

    struct Node *root = NULL;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    int p = 5;
    int q = 15;

    struct Node *ancestor = LCA(root, p, q);

    if(ancestor != NULL)
        printf("LCA of %d and %d = %d",
               p, q, ancestor->data);
    else
        printf("LCA not found");

    return 0;
}