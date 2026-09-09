#include <stdio.h>
#include <stdlib.h>

// Structure of BST node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
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

// Find Lowest Common Ancestor
struct Node* lowestCommonAncestor(
    struct Node* root,
    int p,
    int q)
{
    if (root == NULL)
    {
        return NULL;
    }

    // Both nodes are in left subtree
    if (p < root->data && q < root->data)
    {
        return lowestCommonAncestor(root->left, p, q);
    }

    // Both nodes are in right subtree
    if (p > root->data && q > root->data)
    {
        return lowestCommonAncestor(root->right, p, q);
    }

    // Nodes are on different sides
    // OR one of them is the current root
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
    /*
              6
            /   \
           2     8
          / \   / \
         0   4 7   9
            / \
           3   5
    */

    struct Node* root = NULL;

    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 0);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 3);
    root = insert(root, 5);

    printf("Inorder: ");
    inorder(root);

    int p = 2;
    int q = 8;

    struct Node* lca =
        lowestCommonAncestor(root, p, q);

    if (lca != NULL)
    {
        printf("\nLCA of %d and %d = %d\n",
               p, q, lca->data);
    }

    return 0;
}