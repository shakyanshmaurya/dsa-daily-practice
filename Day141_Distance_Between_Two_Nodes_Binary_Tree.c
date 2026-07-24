#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* LCA(struct Node *root, int n1, int n2) {

    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct Node *left = LCA(root->left, n1, n2);
    struct Node *right = LCA(root->right, n1, n2);

    if(left && right)
        return root;

    return (left != NULL) ? left : right;
}

int findDistance(struct Node *root, int key, int dist) {

    if(root == NULL)
        return -1;

    if(root->data == key)
        return dist;

    int left = findDistance(root->left, key, dist + 1);

    if(left != -1)
        return left;

    return findDistance(root->right, key, dist + 1);
}

int distanceBetweenNodes(struct Node *root, int n1, int n2) {

    struct Node *lca = LCA(root, n1, n2);

    int d1 = findDistance(lca, n1, 0);
    int d2 = findDistance(lca, n2, 0);

    return d1 + d2;
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Distance = %d",
           distanceBetweenNodes(root, 4, 5));

    return 0;
}