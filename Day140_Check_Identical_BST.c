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

int isIdentical(struct Node *root1, struct Node *root2) {

    if(root1 == NULL && root2 == NULL)
        return 1;

    if(root1 == NULL || root2 == NULL)
        return 0;

    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

int main() {

    struct Node *root1 = createNode(10);
    root1->left = createNode(5);
    root1->right = createNode(20);
    root1->left->left = createNode(2);
    root1->left->right = createNode(8);

    struct Node *root2 = createNode(10);
    root2->left = createNode(5);
    root2->right = createNode(20);
    root2->left->left = createNode(2);
    root2->left->right = createNode(8);

    if(isIdentical(root1, root2))
        printf("BSTs are Identical");
    else
        printf("BSTs are Not Identical");

    return 0;
}