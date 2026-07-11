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

int checkChildrenSum(struct Node *root) {

    if(root == NULL)
        return 1;

    if(root->left == NULL &&
       root->right == NULL)
        return 1;

    int left = 0;
    int right = 0;

    if(root->left)
        left = root->left->data;

    if(root->right)
        right = root->right->data;

    return (root->data == left + right) &&
           checkChildrenSum(root->left) &&
           checkChildrenSum(root->right);
}

int main() {

    struct Node *root = createNode(10);

    root->left = createNode(8);
    root->right = createNode(2);

    root->left->left = createNode(3);
    root->left->right = createNode(5);

    if(checkChildrenSum(root))
        printf("Children Sum Property Satisfied");
    else
        printf("Children Sum Property Not Satisfied");

    return 0;
}