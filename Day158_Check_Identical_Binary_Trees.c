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

int areIdentical(struct Node *root1, struct Node *root2) {

    // Both trees are empty
    if(root1 == NULL && root2 == NULL)
        return 1;

    // One tree is empty
    if(root1 == NULL || root2 == NULL)
        return 0;

    // Values are different
    if(root1->data != root2->data)
        return 0;

    // Compare left and right subtrees
    return areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

int main() {

    struct Node *root1 = createNode(1);

    root1->left = createNode(2);
    root1->right = createNode(3);

    root1->left->left = createNode(4);
    root1->left->right = createNode(5);


    struct Node *root2 = createNode(1);

    root2->left = createNode(2);
    root2->right = createNode(3);

    root2->left->left = createNode(4);
    root2->left->right = createNode(5);


    if(areIdentical(root1, root2))
        printf("Both Trees are Identical");
    else
        printf("Trees are Not Identical");

    return 0;
}