#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Info {
    int size;
    int min;
    int max;
    int isBST;
};

int maxBST = 0;

struct Node* createNode(int value) {

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Info largestBST(struct Node *root) {

    struct Info curr;

    if(root == NULL) {

        curr.size = 0;
        curr.min = INT_MAX;
        curr.max = INT_MIN;
        curr.isBST = 1;

        return curr;
    }

    struct Info left = largestBST(root->left);
    struct Info right = largestBST(root->right);

    if(left.isBST &&
       right.isBST &&
       root->data > left.max &&
       root->data < right.min) {

        curr.isBST = 1;
        curr.size = left.size + right.size + 1;

        curr.min = (root->left) ? left.min : root->data;
        curr.max = (root->right) ? right.max : root->data;

        if(curr.size > maxBST)
            maxBST = curr.size;
    }
    else {

        curr.isBST = 0;
        curr.size = 0;
        curr.min = INT_MIN;
        curr.max = INT_MAX;
    }

    return curr;
}

int main() {

    struct Node *root = createNode(50);

    root->left = createNode(30);
    root->right = createNode(60);

    root->left->left = createNode(5);
    root->left->right = createNode(20);

    root->right->left = createNode(45);
    root->right->right = createNode(70);

    root->right->right->left = createNode(65);
    root->right->right->right = createNode(80);

    largestBST(root);

    printf("Largest BST Size = %d", maxBST);

    return 0;
}