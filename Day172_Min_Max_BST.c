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

/* Find Minimum */

struct Node* findMin(struct Node *root) {

    if(root == NULL)
        return NULL;

    while(root->left != NULL)
        root = root->left;

    return root;
}

/* Find Maximum */

struct Node* findMax(struct Node *root) {

    if(root == NULL)
        return NULL;

    while(root->right != NULL)
        root = root->right;

    return root;
}

int main() {

    struct Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 10);

    struct Node *minimum = findMin(root);
    struct Node *maximum = findMax(root);

    printf("Minimum = %d\n", minimum->data);
    printf("Maximum = %d\n", maximum->data);

    return 0;
}