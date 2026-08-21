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

int findPosition(int inorder[], int start, int end, int value) {

    for(int i = start; i <= end; i++) {

        if(inorder[i] == value)
            return i;
    }

    return -1;
}

struct Node* buildTree(
    int preorder[],
    int inorder[],
    int inStart,
    int inEnd,
    int *preIndex
) {

    if(inStart > inEnd)
        return NULL;

    // Preorder ka current element root hai
    int rootValue = preorder[*preIndex];

    (*preIndex)++;

    struct Node *root = createNode(rootValue);

    // Inorder me root ki position find karo
    int position =
        findPosition(inorder, inStart, inEnd, rootValue);

    // Left subtree
    root->left = buildTree(
        preorder,
        inorder,
        inStart,
        position - 1,
        preIndex
    );

    // Right subtree
    root->right = buildTree(
        preorder,
        inorder,
        position + 1,
        inEnd,
        preIndex
    );

    return root;
}

void printInorder(struct Node *root) {

    if(root == NULL)
        return;

    printInorder(root->left);

    printf("%d ", root->data);

    printInorder(root->right);
}

void printPreorder(struct Node *root) {

    if(root == NULL)
        return;

    printf("%d ", root->data);

    printPreorder(root->left);

    printPreorder(root->right);
}

int main() {

    int preorder[] = {1, 2, 4, 5, 3, 6, 7};

    int inorder[] = {4, 2, 5, 1, 6, 3, 7};

    int n = 7;

    int preIndex = 0;

    struct Node *root = buildTree(
        preorder,
        inorder,
        0,
        n - 1,
        &preIndex
    );

    printf("Constructed Tree Inorder: ");
    printInorder(root);

    printf("\nConstructed Tree Preorder: ");
    printPreorder(root);

    return 0;
}