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

int sum = 0;

void convertGST(struct Node *root) {

    if(root == NULL)
        return;

    convertGST(root->right);

    sum += root->data;
    root->data = sum;

    convertGST(root->left);
}

void inorder(struct Node *root) {

    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {

    struct Node *root = createNode(4);

    root->left = createNode(1);
    root->right = createNode(6);

    root->left->left = createNode(0);
    root->left->right = createNode(2);

    root->right->left = createNode(5);
    root->right->right = createNode(7);

    convertGST(root);

    printf("Greater Sum Tree (Inorder):\n");
    inorder(root);

    return 0;
}