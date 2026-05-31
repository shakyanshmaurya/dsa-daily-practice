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

// BST Insertion
struct Node* insert(struct Node* root, int value) {

    if(root == NULL) {
        return createNode(value);
    }

    if(value < root->data) {
        root->left = insert(root->left, value);
    }
    else if(value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder Traversal
void inorder(struct Node* root) {

    if(root == NULL)
        return;

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

int main() {

    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("BST Inorder Traversal:\n");

    inorder(root);

    return 0;
}