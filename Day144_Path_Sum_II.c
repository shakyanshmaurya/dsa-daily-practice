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

void printPath(int path[], int length) {

    for(int i = 0; i < length; i++) {
        printf("%d ", path[i]);
    }

    printf("\n");
}

void pathSum(struct Node *root,
             int target,
             int path[],
             int length) {

    if(root == NULL)
        return;

    // Add current node
    path[length] = root->data;
    length++;

    target = target - root->data;

    // Check leaf
    if(root->left == NULL &&
       root->right == NULL &&
       target == 0) {

        printPath(path, length);
    }

    // Go left
    pathSum(root->left, target, path, length);

    // Go right
    pathSum(root->right, target, path, length);

    // Backtracking
    length--;
}

int main() {

    struct Node *root = createNode(5);

    root->left = createNode(4);
    root->right = createNode(8);

    root->left->left = createNode(11);

    root->left->left->left = createNode(7);
    root->left->left->right = createNode(2);

    root->right->left = createNode(13);
    root->right->right = createNode(4);

    int path[100];

    int target = 22;

    printf("Paths with Sum %d:\n", target);

    pathSum(root, target, path, 0);

    return 0;
}