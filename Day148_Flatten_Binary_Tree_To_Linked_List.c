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

void flatten(struct Node *root) {

    if(root == NULL)
        return;

    flatten(root->left);
    flatten(root->right);

    struct Node *temp = root->right;

    root->right = root->left;
    root->left = NULL;

    struct Node *current = root;

    while(current->right != NULL)
        current = current->right;

    current->right = temp;
}

void printFlattenedTree(struct Node *root) {

    while(root != NULL) {

        printf("%d ", root->data);

        root = root->right;
    }
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(5);

    root->left->left = createNode(3);
    root->left->right = createNode(4);

    root->right->right = createNode(6);

    flatten(root);

    printf("Flattened Tree:\n");

    printFlattenedTree(root);

    return 0;
}