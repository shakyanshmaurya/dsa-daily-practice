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
    int inorder[],
    int postorder[],
    int inStart,
    int inEnd,
    int *postIndex
) {

    if(inStart > inEnd)
        return NULL;

    // Postorder ka last/current element root hai
    int rootValue = postorder[*postIndex];

    (*postIndex)--;

    struct Node *root = createNode(rootValue);

    // Inorder me root ki position find karo
    int position =
        findPosition(inorder, inStart, inEnd, rootValue);

    /*
     * Postorder ko right se left process kar rahe hain,
     * isliye pehle RIGHT subtree banega.
     */

    root->right = buildTree(
        inorder,
        postorder,
        position + 1,
        inEnd,
        postIndex
    );

    root->left = buildTree(
        inorder,
        postorder,
        inStart,
        position - 1,
        postIndex
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

void printPostorder(struct Node *root) {

    if(root == NULL)
        return;

    printPostorder(root->left);

    printPostorder(root->right);

    printf("%d ", root->data);
}

int main() {

    int inorder[] = {4, 2, 5, 1, 6, 3, 7};

    int postorder[] = {4, 5, 2, 6, 7, 3, 1};

    int n = 7;

    int postIndex = n - 1;

    struct Node *root = buildTree(
        inorder,
        postorder,
        0,
        n - 1,
        &postIndex
    );

    printf("Constructed Tree Inorder: ");
    printInorder(root);

    printf("\nConstructed Tree Postorder: ");
    printPostorder(root);

    return 0;
}