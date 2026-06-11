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

int findMaximum(struct Node* root) {

    if(root == NULL)
        return -99999;

    int leftMax =
        findMaximum(root->left);

    int rightMax =
        findMaximum(root->right);

    return max(root->data,
               max(leftMax, rightMax));
}

int main() {

    struct Node* root = createNode(10);

    root->left = createNode(25);
    root->right = createNode(5);

    root->left->left = createNode(40);
    root->left->right = createNode(15);

    printf("Maximum Element = %d",
           findMaximum(root));

    return 0;
}