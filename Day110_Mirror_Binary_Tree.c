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

// Inorder Traversal
void inorder(struct Node* root) {

    if(root == NULL)
        return;

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

// Mirror Function
void mirror(struct Node* root) {

    if(root == NULL)
        return;

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

int main() {

    struct Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Original Tree (Inorder):\n");
    inorder(root);

    mirror(root);

    printf("\nMirror Tree (Inorder):\n");
    inorder(root);

    return 0;
}