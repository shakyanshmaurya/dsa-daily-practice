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

int isLeaf(struct Node *root) {

    if(root == NULL)
        return 0;

    return (root->left == NULL &&
            root->right == NULL);
}

/* Print Left Boundary */

void printLeftBoundary(struct Node *root) {

    struct Node *current = root->left;

    while(current != NULL) {

        if(!isLeaf(current))
            printf("%d ", current->data);

        if(current->left != NULL)
            current = current->left;
        else
            current = current->right;
    }
}

/* Print Leaf Nodes */

void printLeaves(struct Node *root) {

    if(root == NULL)
        return;

    if(isLeaf(root)) {
        printf("%d ", root->data);
        return;
    }

    printLeaves(root->left);
    printLeaves(root->right);
}

/* Print Right Boundary */

void printRightBoundary(struct Node *root) {

    struct Node *current = root->right;

    int stack[100];
    int top = -1;

    while(current != NULL) {

        if(!isLeaf(current))
            stack[++top] = current->data;

        if(current->right != NULL)
            current = current->right;
        else
            current = current->left;
    }

    while(top >= 0) {
        printf("%d ", stack[top--]);
    }
}

/* Boundary Traversal */

void boundaryTraversal(struct Node *root) {

    if(root == NULL)
        return;

    // Root
    if(!isLeaf(root))
        printf("%d ", root->data);

    // Left Boundary
    printLeftBoundary(root);

    // Leaf Nodes
    printLeaves(root);

    // Right Boundary
    printRightBoundary(root);
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    root->left->right->left = createNode(8);
    root->left->right->right = createNode(9);

    printf("Boundary Traversal:\n");

    boundaryTraversal(root);

    return 0;
}