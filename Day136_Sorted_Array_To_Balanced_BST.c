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

struct Node* sortedArrayToBST(int arr[], int start, int end) {

    if(start > end)
        return NULL;

    int mid = (start + end) / 2;

    struct Node *root = createNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

void inorder(struct Node *root) {

    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {

    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *root = sortedArrayToBST(arr, 0, n - 1);

    printf("Inorder Traversal:\n");
    inorder(root);

    return 0;
}