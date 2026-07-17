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

int floorBST(struct Node *root, int key) {

    int floor = -1;

    while(root != NULL) {

        if(root->data == key)
            return root->data;

        if(root->data < key) {
            floor = root->data;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }

    return floor;
}

int ceilBST(struct Node *root, int key) {

    int ceil = -1;

    while(root != NULL) {

        if(root->data == key)
            return root->data;

        if(root->data > key) {
            ceil = root->data;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    return ceil;
}

int main() {

    struct Node *root = createNode(20);

    root->left = createNode(10);
    root->right = createNode(30);

    root->left->left = createNode(5);
    root->left->right = createNode(15);

    root->right->left = createNode(25);
    root->right->right = createNode(35);

    int key = 18;

    printf("Floor = %d\n", floorBST(root, key));
    printf("Ceil = %d", ceilBST(root, key));

    return 0;
}