#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int min(int a, int b) {
    return (a < b) ? a : b;
}

int findMinimum(struct Node* root) {

    if(root == NULL)
        return INT_MAX;

    int leftMin =
        findMinimum(root->left);

    int rightMin =
        findMinimum(root->right);

    return min(root->data,
               min(leftMin, rightMin));
}

int main() {

    struct Node* root = createNode(10);

    root->left = createNode(25);
    root->right = createNode(5);

    root->left->left = createNode(40);
    root->left->right = createNode(15);

    printf("Minimum Element = %d",
           findMinimum(root));

    return 0;
}