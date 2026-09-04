#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

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

// Check whether tree is a valid BST
bool isValidBST(struct Node* root, long long min, long long max)
{
    // Empty tree is a valid BST
    if (root == NULL)
    {
        return true;
    }

    // Current node must be inside the allowed range
    if (root->data <= min || root->data >= max)
    {
        return false;
    }

    // Check left and right subtrees
    return isValidBST(root->left, min, root->data) &&
           isValidBST(root->right, root->data, max);
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

    struct Node* root = createNode(5);

    root->left = createNode(3);
    root->right = createNode(7);

    root->left->left = createNode(2);
    root->left->right = createNode(4);

    root->right->left = createNode(6);
    root->right->right = createNode(8);

    if (isValidBST(root, LLONG_MIN, LLONG_MAX))
    {
        printf("Valid BST\n");
    }
    else
    {
        printf("Not a Valid BST\n");
    }

    return 0;
}