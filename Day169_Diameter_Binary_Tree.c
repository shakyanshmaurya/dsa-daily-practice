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

/*
    Returns height of tree
    and updates diameter.
*/

int height(struct Node *root, int *diameter) {

    if(root == NULL)
        return 0;

    int leftHeight =
        height(root->left, diameter);

    int rightHeight =
        height(root->right, diameter);

    /*
        Path passing through current node
    */

    int currentDiameter =
        leftHeight + rightHeight;

    if(currentDiameter > *diameter)
        *diameter = currentDiameter;

    /*
        Height of current node
    */

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int diameter = 0;

    height(root, &diameter);

    printf("Diameter of Binary Tree = %d",
           diameter);

    return 0;
}