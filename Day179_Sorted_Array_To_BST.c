#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Convert sorted array to balanced BST
struct Node* sortedArrayToBST(int arr[], int left, int right) {

    // Base case
    if (left > right) {
        return NULL;
    }

    // Find middle element
    int mid = left + (right - left) / 2;

    // Middle element becomes root
    struct Node* root = createNode(arr[mid]);

    // Build left subtree
    root->left = sortedArrayToBST(arr, left, mid - 1);

    // Build right subtree
    root->right = sortedArrayToBST(arr, mid + 1, right);

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

int main() {

    int arr[] = {-10, -3, 0, 5, 9};

    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* root =
        sortedArrayToBST(arr, 0, n - 1);

    printf("Inorder of BST: ");

    inorder(root);

    return 0;
}