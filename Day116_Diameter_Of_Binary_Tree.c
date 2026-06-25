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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* root) {

    if(root == NULL)
        return 0;

    return 1 + max(
        height(root->left),
        height(root->right)
    );
}

int diameter(struct Node* root) {

    if(root == NULL)
        return 0;

    int leftHeight =
        height(root->left);

    int rightHeight =
        height(root->right);

    int rootDiameter =
        leftHeight +
        rightHeight +
        1;

    int leftDiameter =
        diameter(root->left);

    int rightDiameter =
        diameter(root->right);

    return max(
        rootDiameter,
        max(leftDiameter,
            rightDiameter)
    );
}

int main() {

    struct Node* root =
        createNode(1);

    root->left =
        createNode(2);

    root->right =
        createNode(3);

    root->left->left =
        createNode(4);

    root->left->right =
        createNode(5);

    printf("Diameter = %d",
           diameter(root));

    return 0;
}