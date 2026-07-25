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

void printPath(int path[], int length) {

    for(int i = 0; i < length; i++)
        printf("%d ", path[i]);

    printf("\n");
}

void rootToLeaf(struct Node *root, int path[], int length) {

    if(root == NULL)
        return;

    path[length] = root->data;
    length++;

    if(root->left == NULL && root->right == NULL) {
        printPath(path, length);
        return;
    }

    rootToLeaf(root->left, path, length);
    rootToLeaf(root->right, path, length);
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int path[100];

    printf("Root to Leaf Paths:\n");

    rootToLeaf(root, path, 0);

    return 0;
}