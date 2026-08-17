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

struct Node* findKthAncestor(struct Node *root, int target, int *k) {

    if(root == NULL)
        return NULL;

    // Target node found
    if(root->data == target)
        return root;

    struct Node *leftResult =
        findKthAncestor(root->left, target, k);

    if(leftResult != NULL) {

        if(*k > 0)
            (*k)--;

        if(*k == 0) {
            printf("Kth Ancestor = %d\n", root->data);
            return NULL;
        }

        return leftResult;
    }

    struct Node *rightResult =
        findKthAncestor(root->right, target, k);

    if(rightResult != NULL) {

        if(*k > 0)
            (*k)--;

        if(*k == 0) {
            printf("Kth Ancestor = %d\n", root->data);
            return NULL;
        }

        return rightResult;
    }

    return NULL;
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->left->left->left = createNode(6);

    int target = 6;
    int k = 2;

    findKthAncestor(root, target, &k);

    return 0;
}