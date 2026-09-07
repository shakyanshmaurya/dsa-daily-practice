#include <stdio.h>
#include <stdlib.h>

// Structure of BST node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data)
{
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert into BST
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

// Reverse inorder
void kthLargest(struct Node* root, int* k, int* answer)
{
    if (root == NULL)
    {
        return;
    }

    // Visit right subtree first
    kthLargest(root->right, k, answer);

    // Process current node
    if (*k == 1)
    {
        *answer = root->data;
        return;
    }

    (*k)--;

    // Visit left subtree
    kthLargest(root->left, k, answer);
}

// Normal inorder
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
    /*
             5
            / \
           3   7
          / \ / \
         2  4 6  8
    */

    struct Node* root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    printf("Inorder: ");
    inorder(root);

    int k = 2;
    int answer = -1;

    kthLargest(root, &k, &answer);

    printf("\n%dnd largest element: %d\n", 2, answer);

    return 0;
}