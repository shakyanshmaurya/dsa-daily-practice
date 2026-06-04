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

struct Node* insert(struct Node* root, int value) {

    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct Node* findMin(struct Node* root) {

    while(root->left != NULL)
        root = root->left;

    return root;
}

struct Node* deleteNode(struct Node* root, int key) {

    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else {

        // No child
        if(root->left == NULL &&
           root->right == NULL) {

            free(root);
            return NULL;
        }

        // One child
        if(root->left == NULL) {

            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        if(root->right == NULL) {

            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Two children
        struct Node* temp =
            findMin(root->right);

        root->data = temp->data;

        root->right =
            deleteNode(root->right,
                       temp->data);
    }

    return root;
}

void inorder(struct Node* root) {

    if(root == NULL)
        return;

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

int main() {

    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    root = deleteNode(root, 20);

    printf("BST After Deletion:\n");

    inorder(root);

    return 0;
}