#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {

    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int isMirror(struct Node* left,
             struct Node* right) {

    if(left == NULL &&
       right == NULL)
        return 1;

    if(left == NULL ||
       right == NULL)
        return 0;

    return (left->data ==
            right->data)

           &&

           isMirror(left->left,
                    right->right)

           &&

           isMirror(left->right,
                    right->left);
}

int isSymmetric(struct Node* root) {

    if(root == NULL)
        return 1;

    return isMirror(root->left,
                    root->right);
}

int main() {

    struct Node* root =
        createNode(1);

    root->left =
        createNode(2);

    root->right =
        createNode(2);

    root->left->left =
        createNode(3);

    root->left->right =
        createNode(4);

    root->right->left =
        createNode(4);

    root->right->right =
        createNode(3);

    if(isSymmetric(root))
        printf("Tree is Symmetric");
    else
        printf("Tree is Not Symmetric");

    return 0;
}
	