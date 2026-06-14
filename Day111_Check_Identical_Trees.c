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

int identical(struct Node* root1,
              struct Node* root2) {

    if(root1 == NULL &&
       root2 == NULL)
        return 1;

    if(root1 == NULL ||
       root2 == NULL)
        return 0;

    return (root1->data ==
            root2->data)

           &&

           identical(root1->left,
                     root2->left)

           &&

           identical(root1->right,
                     root2->right);
}

int main() {

    struct Node* root1 =
        createNode(1);

    root1->left =
        createNode(2);

    root1->right =
        createNode(3);


    struct Node* root2 =
        createNode(1);

    root2->left =
        createNode(2);

    root2->right =
        createNode(3);

    if(identical(root1, root2))
        printf("Trees are Identical");
    else
        printf("Trees are Not Identical");

    return 0;
}