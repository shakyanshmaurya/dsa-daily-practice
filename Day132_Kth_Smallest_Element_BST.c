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

int count = 0;
int answer = -1;

void kthSmallest(struct Node *root, int k) {

    if(root == NULL)
        return;

    kthSmallest(root->left, k);

    count++;

    if(count == k) {
        answer = root->data;
        return;
    }

    kthSmallest(root->right, k);
}

int main() {

    struct Node *root = createNode(20);

    root->left = createNode(10);
    root->right = createNode(30);

    root->left->left = createNode(5);
    root->left->right = createNode(15);

    root->right->left = createNode(25);
    root->right->right = createNode(35);

    int k = 3;

    kthSmallest(root, k);

    printf("%dth Smallest Element = %d", k, answer);

    return 0;
}