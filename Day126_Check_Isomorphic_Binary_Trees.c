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

int isIsomorphic(struct Node *root1,
                 struct Node *root2) {

    if(root1 == NULL && root2 == NULL)
        return 1;

    if(root1 == NULL || root2 == NULL)
        return 0;

    if(root1->data != root2->data)
        return 0;

    return (
        (isIsomorphic(root1->left, root2->left) &&
         isIsomorphic(root1->right, root2->right))
        ||
        (isIsomorphic(root1->left, root2->right) &&
         isIsomorphic(root1->right, root2->left))
    );
}

int main() {

    struct Node *root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);

    struct Node *root2 = createNode(1);
    root2->left = createNode(3);
    root2->right = createNode(2);
    root2->right->right = createNode(4);

    if(isIsomorphic(root1, root2))
        printf("Trees are Isomorphic");
    else
        printf("Trees are Not Isomorphic");

    return 0;
}