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

int height(struct Node* root) {

    if(root == NULL)
        return 0;

    int leftHeight =
        height(root->left);

    int rightHeight =
        height(root->right);

    return 1 +
        (leftHeight > rightHeight ?
         leftHeight : rightHeight);
}

int isBalanced(struct Node* root) {

    if(root == NULL)
        return 1;

    int leftHeight =
        height(root->left);

    int rightHeight =
        height(root->right);

    int diff =
        leftHeight - rightHeight;

    if(diff < 0)
        diff = -diff;

    if(diff > 1)
        return 0;

    return isBalanced(root->left)
        &&
        isBalanced(root->right);
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

    if(isBalanced(root))
        printf("Tree is Balanced");
    else
        printf("Tree is Not Balanced");

    return 0;
}