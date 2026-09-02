}#include <stdio.h>
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

struct Node* insert(struct Node *root, int value) {

    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* Inorder Successor */

struct Node* successor(struct Node *root, int key) {

    struct Node *successor = NULL;

    while(root != NULL) {

        if(key < root->data) {

            successor = root;
            root = root->left;
        }

        else if(key > root->data) {

            root = root->right;
        }

        else {

            if(root->right != NULL) {

                root = root->right;

                while(root->left != NULL)
                    root = root->left;

                successor = root;
            }

            break;
        }
    }

    return successor;
}

/* Inorder Predecessor */

struct Node* predecessor(struct Node *root, int key) {

    struct Node *predecessor = NULL;

    while(root != NULL) {

        if(key > root->data) {

            predecessor = root;
            root = root->right;
        }

        else if(key < root->data) {

            root = root->left;
        }

        else {

            if(root->left != NULL) {

                root = root->left;

                while(root->right != NULL)
                    root = root->right;

                predecessor = root;
            }

            break;
        }
    }

    return predecessor;
}

int main() {

    struct Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int key = 50;

    struct Node *pre = predecessor(root, key);
    struct Node *suc = successor(root, key);

    if(pre != NULL)
        printf("Predecessor of %d = %d\n",
               key, pre->data);
    else
        printf("Predecessor does not exist\n");

    if(suc != NULL)
        printf("Successor of %d = %d\n",
               key, suc->data);
    else
        printf("Successor does not exist\n");

    return 0;
}