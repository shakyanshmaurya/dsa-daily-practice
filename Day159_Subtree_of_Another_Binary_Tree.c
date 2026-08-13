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

/* Check whether two trees are identical */

int areIdentical(struct Node *root1, struct Node *root2) {

    if(root1 == NULL && root2 == NULL)
        return 1;

    if(root1 == NULL || root2 == NULL)
        return 0;

    if(root1->data != root2->data)
        return 0;

    return areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

/* Check whether root2 is a subtree of root1 */

int isSubtree(struct Node *root, struct Node *subRoot) {

    if(subRoot == NULL)
        return 1;

    if(root == NULL)
        return 0;

    if(areIdentical(root, subRoot))
        return 1;

    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}

int main() {

    /* Main Tree */

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);


    /* Subtree */

    struct Node *subRoot = createNode(2);

    subRoot->left = createNode(4);
    subRoot->right = createNode(5);


    if(isSubtree(root, subRoot))
        printf("Tree B is a Subtree of Tree A");
    else
        printf("Tree B is NOT a Subtree of Tree A");

    return 0;
}