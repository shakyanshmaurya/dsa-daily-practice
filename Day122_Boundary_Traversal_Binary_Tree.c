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

int isLeaf(struct Node *node) {

    return (node->left == NULL &&
            node->right == NULL);
}

void leftBoundary(struct Node *root) {

    if(root == NULL || isLeaf(root))
        return;

    printf("%d ", root->data);

    if(root->left)
        leftBoundary(root->left);
    else
        leftBoundary(root->right);
}

void leafNodes(struct Node *root) {

    if(root == NULL)
        return;

    if(isLeaf(root)) {

        printf("%d ", root->data);
        return;
    }

    leafNodes(root->left);
    leafNodes(root->right);
}

void rightBoundary(struct Node *root) {

    if(root == NULL || isLeaf(root))
        return;

    if(root->right)
        rightBoundary(root->right);
    else
        rightBoundary(root->left);

    printf("%d ", root->data);
}

void boundaryTraversal(struct Node *root) {

    if(root == NULL)
        return;

    printf("%d ", root->data);

    leftBoundary(root->left);

    leafNodes(root->left);
    leafNodes(root->right);

    rightBoundary(root->right);
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