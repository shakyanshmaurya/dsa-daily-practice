#include <stdio.h>
#include <stdlib.h>

// Structure of a Binary Search Tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// Find minimum node
struct Node* findMin(struct Node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

// Delete a node from BST
struct Node* deleteNode(struct Node* root, int key)
{
    // Key not found
    if (root == NULL)
    {
        return NULL;
    }

    // Search left
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    // Search right
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    // Node found
    else
    {
        // Case 1: No left child
        if (root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: No right child
        if (root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct Node* successor = findMin(root->right);

        // Copy successor's value
        root->data = successor->data;

        // Delete successor
        root->right = deleteNode(root->right, successor->data);
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct Node* root = NULL;

    // Creating BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);

    printf("Before deletion: ");
    inorder(root);

    // Delete node 3
    root = deleteNode(root, 3);

    printf("\nAfter deletion: ");
    inorder(root);

    return 0;
}